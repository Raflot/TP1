#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char input[128];
    pid_t pid;
    int status;
    char prompt[64] = "enseash % ";
    struct timespec start_time, end_time;
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\nTapez 'exit' pour quitter.\n", 59);

    while (1) {

        write(STDOUT_FILENO, prompt, strlen(prompt));

        //read user input
        ssize_t bytes_read = read(STDIN_FILENO, input, sizeof(input) - 1);

        //change the end
        input[bytes_read - 1] = '\0';

        //"exit" command
        if (strcmp(input, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 12);
            break;
        }

        //example
        if (strcmp(input, "fortune") == 0) {
            char fortune_msg[] = "hahaha\n";
            write(STDOUT_FILENO, fortune_msg, strlen(fortune_msg));
            continue; //return to prompt
        }
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        pid = fork();
        if (pid == 0) {
            //child, execute the command
            execlp(input, input, (char *)NULL);

            //if fail, print error and exit
            char error_msg[] = "Error: Command not found.\n";
            write(STDERR_FILENO, error_msg, strlen(error_msg));
            _exit(1);
        } else if (pid > 0) {
            //parent wait
            waitpid(pid, &status, 0);
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            long time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000;
            //update prompt
            if (WIFEXITED(status)) {
                snprintf(prompt, sizeof(prompt), "enseash [exit:%d|%ldms] %% ", WEXITSTATUS(status), time);
            } else if (WIFSIGNALED(status)) {
                snprintf(prompt, sizeof(prompt), "enseash [sign:%d|%ldms] %% ", WTERMSIG(status), time);
            }
        } else {
            //error
            char fork_error[] = "Error: Fork failed.\n";
            write(STDERR_FILENO, fork_error, strlen(fork_error));
        }
    }

    return 0;
}
