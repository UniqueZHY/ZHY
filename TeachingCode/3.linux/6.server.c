/*************************************************************************
	> File Name: 6.server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时04分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }
    
    printf("Socket bind\n");
    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }

    while (1) {
        int sockfd;
        //没成功
        printf("Socket before accept.\n");
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        //成功
        char name[20] = {0};//说名字，是谁
        printf("Socket after accept.\n");
        if (recv(sockfd, name, sizeof(name), 0) <= 0) {
            close(sockfd);
            continue;
        }
        printf("Socket recved.\n");
        printf("name: %s\n", name);
        close(sockfd);
    }

    return 0;
}

