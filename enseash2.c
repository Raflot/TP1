#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[]){
    // write the message with write
    const char *message = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
    size_t lenmsg = strlen(message);
    write(1, message, lenmsg);
    // Define le prompt 
    //char* prompt = "Pour quitter, tapez 'exit'.";

    // show the prompt
    //size_t lenprompt = strlen(prompt);
    //write(1, prompt, lenprompt);

    // read the imput
    //char input[256];
    //fgets(input, 256, stdin);

}