#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

void stop(int sig)
{
    close(s);
    close(sc);
    printf("\n Server is terminated.\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int bytes;
    int err;
    int flag;
    char on;
    char buffer[BufSIZE];
    unsigned int server_size;
    unsigned int client_size;
    struct sockaddr_in server;
    struct sockaddr_in client;

    on = 1;
    flag = 0;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT_NO);
    server_size = sizeof server;
    client_size = sizeof client;
    signal(SIGINT, stop);
    signal(SIGTERM, stop);

    sc = socket(AF_INET, SOCK_STREAM, 0);
    if (sc < 0)
    {
        fprintf(stderr, "%s: Sockert creation error.\n", argv[0]);
        exit(2);
    }

    setsockopt(sc, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
    setsockopt(sc, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

    err = bind(sc, (struct sockaddr *)&server, server_size);
    if (err < 0)
    {
        fprintf(stderr, "%s: Binding error.\n", argv[0]);
        exit(3);
    }

    err = listen(sc, CQL);
    if (err < 0)
    {
        fprintf(stderr, "%s: Listening error.\n", argv[0]);
        exit(4);
    }
    printf("Type this into a browser: \033[0;31m 127.0.0.1:%d] \033[0m\n");
}