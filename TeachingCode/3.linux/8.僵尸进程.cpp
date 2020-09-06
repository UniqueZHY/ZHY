/*************************************************************************
	> File Name: 8.僵尸进程.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 17时58分12秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<arpa/inet.h>

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    int *status;
    port = atoi(argv[1]);

    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_listen, (struct sockaddr*)&server, sizeof(server)) <0){
        perror("bind");
        exit(1);
    }
    printf("sockfd bind.\n");
    if(listen(server_listen, 20) < 0){
        perror("listen");
        exit(1);
    }
    //父进程保持不动一直等着accept，来一个就分一个子进程
    //这样就不会发生一个进程阻塞其他进程不能进来的情况
    while(1){
        int sockfd;
    printf("sockfd before accept.\n");
        if((sockfd = accept(server_listen, NULL, NULL)) <0){
            perror("accept");
            close(sockfd);
            continue;
        }
        //fork 分户一个子进程
        pid_t pid;
        if((pid = fork()) < 0){
            perror("fork");
            continue;
        }
        //等于0 说明是子进程，子进程操作
        if(pid == 0){
            close(server_listen);
            char nume[20] = {0};
            if(recv(sockfd, nume, sizeof(nume), 0) <=0){
                perror("recv");
                close(sockfd);
            }
            printf("nume: %s\n", nume);
            exit(0);
        }else {
			//....
            wait(status);
            }
        }

    return 0;
}
