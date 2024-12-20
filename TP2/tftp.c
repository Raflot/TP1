#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TFTP_PORT "69"
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *filename = argv[2];
    
    struct addrinfo hints, *res;
    int soc, info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP

    // Resolve hostname to IP address
    info = getaddrinfo(host, TFTP_PORT, &hints, &res);
    if (info != 0) {
        printf("error addr");
    }

    // Create UDP socket
    soc = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (soc == -1) {
        perror("error socket");
    }

    printf("Socket created successfully. The file will be sent to: %s\n", host);

    const char *mode = "octet";
    size_t buffer_size = 2 + strlen(filename) + 1 + strlen(mode) + 1;
    char *buffer = malloc(buffer_size);

    //create the corect data
    memset(buffer, 0, buffer_size);
    buffer[0] = 0;
    buffer[1] = 1;
    strcpy(buffer + 2, filename);
    strcpy(buffer + 2 + strlen(filename) + 1, mode);

    // Send RRQ
    ssize_t bytes_sent = sendto(soc, buffer, buffer_size, 0, res->ai_addr, res->ai_addrlen);

    printf("TFTP Read Request sent (%zd bytes).\n", bytes_sent);

    free(buffer);
    close(soc);
    freeaddrinfo(res);

    return EXIT_SUCCESS;
}
