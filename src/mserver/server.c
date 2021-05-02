#define PORT 8080
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

struct sockaddr_in address;
void initialize_socket(struct sockaddr_in);
void attach_to_port();


typedef struct
{
    int opt;
    int server_fd;
    int new_socket;
    int value_read;
    char buffer[1024];
    char hello[25];
    int address_len;
} Server;


void initialize_socket(struct sockaddr_in addressIn)
{
    Server *server = malloc(sizeof(Server));
    server -> opt = 1;

    if ((server -> server_fd = socket(AF_INET, SOCK_STREAM, 0) == 0))
    {
        perror("Socket failed to initialize");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server -> server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                    &server -> opt, sizeof(server -> opt)))
    {
        perror("setsocketopt");
        exit(EXIT_FAILURE);
    } else
    {
        addressIn.sin_family = AF_INET;
        addressIn.sin_addr.s_addr = INADDR_ANY;
        addressIn.sin_port = htons(PORT);
    }
}

void attach_to_port(Server *server)
{
    if (bind(server -> server_fd, (struct sockaddr *) &address, sizeof(address)) < 0)
    {
        perror("Unable to connect to port.");
        exit(EXIT_FAILURE);
    }
    if (listen(server -> server_fd, 3) < 0)
    {
        perror("Listen");
        exit(EXIT_FAILURE);
    }
    if ((server -> new_socket = accept(server -> server_fd,
                                       (struct sockaddr *) (struct socket_address_in *) &address,
                                                                (socklen_t*) &server -> address_len)) < 0)
    {
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    server -> value_read = read(server -> new_socket, server -> buffer, 1024);
    printf("%s\n", server -> buffer);
    send(server -> new_socket, server -> hello, strlen(server -> hello), 0);
    printf("Message sent\n");
}

