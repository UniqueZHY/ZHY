/*************************************************************************
	> File Name: 13.1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 13时45分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <pthread.h>

static void *pthread(void *arg){
    int sockfd =*(int *)arg;
    char name[20] = {0};
    if(recv(sockfd, name, sizeof(name), 0) <=0){
        perror("recv"); 
    }
    printf("name: %s\n", name);
}

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    int *status;
  	//pthread_t tidp;
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
    while(1){
        int sockfd;
        pthread_t tidp;
    	printf("sockfd before accept.\n");
        if((sockfd = accept(server_listen, NULL, NULL)) <0){
            perror("accept");
            close(sockfd);
            continue;
        }
        if ((pthread_create(&tidp, NULL, pthread, &sockfd)) == -1)  {
            printf("create error!\n");
            return 1;
        }
       
        if (pthread_join(tidp, NULL)){
            printf("thread is not exit...\n");
            return -2;   
        }
    }
    return 0;
}
