#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TFTP_PORT 69
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{

    const char *server_ip = "10.10.32.11";
    const char *filename = "haa.txt";
    const char *mode = "Octet";

    // UDP socket
    int soc = socket(AF_INET, SOCK_DGRAM, 0);
    if (soc = -1)
    {
        perror("error");
    }

    close(soc);
}
