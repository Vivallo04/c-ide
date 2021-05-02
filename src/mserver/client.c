#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

struct sockaddr_in server_address;
char buffer[1024] = {0};
char *hello = "Hello from the client";
int socket1 = 0;
int value_read;

int create_socket(int);
int convert_to_binary();

/*
int main(int argc, char const *argv[])
{
    create_socket(socket1);
    convert_to_binary(socket1);
}*/
int create_socket(int socket1)
{
    if ((socket1 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error...\n");
        return -1;
    } else
    {
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT);
    }
}

int convert_to_binary(int socket)
{
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("Invalid address || Address not supported: %s\n", server_address);
        return -1;
    }
    if (connect(socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed");
        return -1;
    }
    send(socket, hello, strlen(hello), 0);
    printf("Hello message sent");

    value_read = read(socket, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}
