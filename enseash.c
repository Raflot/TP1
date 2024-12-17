#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    char input[128];
    pid_t pid;
    int status;

    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", 31);
    write(STDOUT_FILENO, "Tapez 'exit' pour quitter.\n", 27);
    
    while (1) {
        write(STDOUT_FILENO, "enseash % ", 10);

        ssize_t bytes_read = read(STDIN_FILENO, input, sizeof(input) - 1);
        if (bytes_read <= 0) {
            break;
        }
        input[bytes_read - 1] = '\0';

        if (strcmp(input, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            break;
        }

        pid = fork();
        if (pid == 0) {
            //Child that execute the command
            execlp(input, input, (char *)NULL);
            //If fail, print error and exit
            perror("Error");
            _exit(1);
        } else if (pid > 0) {
            //Wait for the child to finish
            waitpid(pid, &status, 0);
        } else {
            //Fork error
            perror("Fork failed");
        }
    }


}