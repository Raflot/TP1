#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{
    // write the message with write
    const char *message = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
    size_t lenmsg = strlen(message);
    write(1, message, lenmsg);
    // Define the prompt
    char *prompt = "ensea %";

    // show the prompt
    size_t lenprompt = strlen(prompt);
    write(1, prompt, lenprompt);

    // read the imput
    char input[256];
    fgets(input, 256, stdin);

    while (1) {
        // Show the prompt
        size_t lenprompt = strlen(prompt);
        write(1, prompt, lenprompt);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // exit if the end is reached to avoid repetition
        }

        // Remove the newline character from the input
        size_t lenimp = strlen(input);
        if (input[lenimp - 1] == '\n') {
            input[lenimp - 1] = '\0';
        }
        //exit command
        if (strcmp(input, "exit") == 0) {
            break;
        }

    }

}