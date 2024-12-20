#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TFTP_PORT "69"
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("error");
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *filename = argv[2];
    
    struct addrinfo hints, *res;
    int soc, info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_DGRAM;  // UDP

    //addrinfo
    info = getaddrinfo(host, TFTP_PORT, &hints, &res);
    if (info != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(info));
        return EXIT_FAILURE;
    }

    //UDP socket
    soc = socket(AF_INET, SOCK_DGRAM, 0);
    if (soc == -1) {
        perror("error");
        return EXIT_FAILURE;
    }

    printf("socket created successfully. file send to: %s\n", host);

    close(soc);
    freeaddrinfo(res);

    return EXIT_SUCCESS;
}
