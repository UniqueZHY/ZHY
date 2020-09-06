/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 20时23分33秒
 ************************************************************************/
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>


int main(int argc, char **argv){
    int sockfd, port;
    struct sockaddr_in server;
    if(argc != 3){
        fprintf(stderr, "Usage: %s ip oprt\n",argv[0]);
        exit(1);
    }
    //int atoi(const char *str) 
    //把参数 str 所指向的字符串转换为一个整数（类型为 int 型）
    port = atoi(argv[2]);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    //创建套接字，门
    if (sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(1);
    }
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("connect");
        exit(1);
    }
    if(send(sockfd, "ZhangHongYan", sizeof("ZhangHongYan"), 0) < 0){
        perror("send");
        exit(1);
    }
    close(sockfd);
    return 0;
}
