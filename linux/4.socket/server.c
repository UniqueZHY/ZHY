/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时05分12秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage:%s port\n", argv[0]);
        exit(1);
    } 
    //定义端口
    int port, server_listen;
    //int atoi(const char *str) 
    //把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
    port = atoi(argv[1]);
 //向操作系统申请一个套接字，并判断申请是否成功                   
    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);//地址转换
    server.sin_addr.s_addr = INADDR_ANY;//任何的IP都可以
    //绑定IP                  因为用的结构体是sockaddr_in,so强制类型转换
    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }

    while (1) {
        int sockfd;
        //用来接受sockfd的socket连接
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        char name[20] = {0};
        if (recv(sockfd, name, sizeof(name), 0) <= 0) {
            close(sockfd);
            continue;
        }
        printf("name: %s\n", name);
        close(sockfd);
    }
    return 0;
}
