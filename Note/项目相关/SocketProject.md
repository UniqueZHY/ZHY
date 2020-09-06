# `SocketProject`

## `SocketProject/common/`

### `head.h`

```c
/*************************************************************************
	> File Name: ../common/head.h
	> Author:
	> Mail: 
	> Created Time: 六  3/28 14:23:19 2020
 ************************************************************************/

#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pwd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <poll.h>
#include <sys/select.h>
#include <errno.h>
#endif

```



### `chatroom.h`

```c
*****************************************************
	> File Name: chatroom.h
	> Author: 
	> Mail:
	> Created Time: 日  3/29 16:26:37 2020
 ************************************************************************/

#ifndef _CHATROOM_H
#define _CHATROOM_H

#include "head.h"

struct Msg {
    char from[20];
    int flag;
    char message[512];
};  



struct RecvMsg {
    struct Msg msg;
    int retval;
};


int chat_send(struct Msg msg, int fd) {
    if (send(fd, (void *)&msg, sizeof(msg), 0) <= 0) {
        return -1;
    }
    return 0;
}

struct RecvMsg chat_recv(int fd) {
    struct RecvMsg tmp;
    memset(&tmp, 0, sizeof(tmp));
    if (recv(fd, &tmp.msg, sizeof(struct Msg), 0) <= 0) {
        tmp.retval = -1;
    }
    return tmp;
}


#define MAX_CLIENT 512
#endif

```

### `color.h`

```c
/*************************************************************************
	> File Name: color.h
	> Author: 
	> Mail:
	> Created Time: 日  3/29 18:51:28 2020
 ************************************************************************/

#ifndef _COLOR_H
#define _COLOR_H

#define NONE "\033[0m"
#define BLACK "\033[0;30m"
#define L_BLACK "\033[1;30m"
#define RED "\033[0;31m"
#define L_RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define L_GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define L_YELLOW "\033[1;33m"
#define BLUE "\033[0;34m"
#define L_BLUE "\033[1;34m"
#define L_PINK "\033[1;35m"
#define PINK "\033[0;35m"
#endif

```

### `common.c`

```c
/*************************************************************************
	> File Name: common.c
	> Author:
	> Mail:
	> Created Time: Sat 28 Mar 2020 08:41:00 PM CST
 ************************************************************************/

#include "head.h"

char *get_value(char *path, char *key) {
    FILE *fp = NULL;
    ssize_t nrd;
    char *line = NULL, *sub = NULL;
    extern char conf_ans[50];
    size_t linecap;
    if (path == NULL || key == NULL) {
        fprintf(stderr, "Error in argument!\n");
        return NULL;
    }
    if ((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return NULL;
    }
    while ((nrd = getline(&line, &linecap, fp)) != -1) {
        if ((sub = strstr(line, key)) == NULL) 
            continue;
        else {
            if (line[strlen(key)] == '=') {
                strncpy(conf_ans, sub + strlen(key) + 1, nrd - strlen(key) - 2);
                *(conf_ans + nrd - strlen(key) - 2) = '\0';
                break;
            }
        }
    }
    free(line);
    fclose(fp);
    if (sub == NULL) {
        return NULL;
    }
    return conf_ans;
}



void make_nonblock_ioctl(int fd){
    unsigned long ul = 1;
    ioctl(fd, FIONBIO, &ul);
}


void make_block_ioctl(int fd) {
    unsigned long ul = 0;
    ioctl(fd, FIONBIO, &ul);
}


void make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}

void make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return ;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}

```

### `common.h`

```c
/*************************************************************************
	> File Name: common.h
	> Author: suyelu
	> Mail: suyelu@haizeix.com
	> Created Time: Sat 28 Mar 2020 08:43:27 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
char conf_ans[50] = {0};
char *get_value(char *path, char *key);
void make_nonblock_ioctl(int fd);
void make_block_ioctl(int fd);
void make_nonblock(int fd);
void make_block(int fd);
#endif

```

### `tcp_client.c`

```c
/*************************************************************************
	> File Name: client.c
	> Author:
	> Mail: 
	> Created Time: 日  3/22 20:21:53 2020
 ************************************************************************/

#include  "head.h"
#include "common.h"

int socket_connect(char *host, int port) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("Socket create.\n");
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return -1;
    }
    return sockfd;
}

int socket_connect_timeout(char *host, int port, long timeout) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    make_nonblock(sockfd);

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = timeout;

    fd_set wfds;
    FD_ZERO(&wfds);
    FD_SET(sockfd, &wfds);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        int retval, error = -1;
        int len = sizeof(int);
        retval = select(sockfd + 1, NULL, &wfds, NULL, &tv);
        if (retval < 0) {
            close(sockfd);
            return -1;
        } else if (retval) {
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len) < 0) {
                close(sockfd);
                return -1;
            }
            if (error) {
                close(sockfd);
                return -1;
            }
        } else {
            printf("Connect Time Out!\n");
            close(sockfd);
            return -1;
        }
    }
    make_block(sockfd);
    return sockfd;
}

```

### `tcp_client.h`

```c
/*************************************************************************
	> File Name: tcp_client.h
	> Author: 
	> Mail:
	> Created Time: 六  3/28 14:34:41 2020
 ************************************************************************/

#ifndef _TCP_CLIENT_H
#define _TCP_CLIENT_H
int socket_connect(char *host, int port);
int socket_connect_timeout(char *host, int port, long timeout);
#endif

```

### `tcp_server.c`

```c
/*************************************************************************
	> File Name: server.c
	> Author:
	> Mail: 
	> Created Time: Sun 22 Mar 2020 08:24:46 PM CST
 ************************************************************************/

#include "head.h"
int socket_create(int port) {
    int server_listen;
    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    struct linger m_linger;
    m_linger.l_onoff = 1;
    m_linger.l_linger = 5;
    if (setsockopt(server_listen, SOL_SOCKET, SO_LINGER, &m_linger, (socklen_t)sizeof(m_linger)) < 0) {
        return -1;
    }
    int flag = 1;
    if (setsockopt(server_listen, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) < 0) {
        return -1;
    }


    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    if (listen(server_listen, 20) < 0){
        return -1;
    }
    return server_listen;
}

```

### `tcp_server.h`

```c
/*************************************************************************
	> File Name: tcp_server.h
	> Author: 
	> Mail:
	> Created Time: 六  3/28 14:24:14 2020
 ************************************************************************/

#ifndef _TCP_SERVER_H
#define _TCP_SERVER_H
int socket_create(int port);
#endif

```

### `udp_server.c`

```c
/*************************************************************************
	> File Name: udp_server.c
	> Author: suyelu
	> Mail: suyelu@haizeix.com
	> Created Time: Sun 22 Mar 2020 08:24:46 PM CST
 ************************************************************************/

#include "head.h"
int socket_create_udp(int port) {
    int server_listen;
    if ((server_listen = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    
    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }

    return server_listen;
}


```

### `udp_server.h`

```c
/*************************************************************************
	> File Name: udp_server.h
	> Author: 
	> Mail:
	> Created Time: 六  3/28 14:24:14 2020
 ************************************************************************/

#ifndef _TCP_SERVER_H
#define _TCP_SERVER_H
int socket_create_udp(int port);
#endif

```

### `udp_client.c`

```c
/*************************************************************************
	> File Name: udp_client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月31日 星期日 13时01分37秒
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>


int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "Usage: %s ip oprt\n",argv[0]);
        exit(1);
    }
    int sockfd, port, n = 0;
    struct sockaddr_in server;
    char buff[512];
   if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("socket");
        exit(1);
    }
    port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    
    while(1){
        fgets(buff, sizeof(buff), stdin);
        if((n = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr*)&server, sizeof(server) )) < 0){
                perror("sendto");
        }
        if((n = recvfrom(sockfd, buff, sizeof(buff), 0, NULL ,0 )) < 0){
            perror("recvfrom");
        }
            printf("buff: %s", buff);
        

    }

    return 0;
}

```



## `SocketProject/client`

### `client.c`

```c
/*************************************************************************
	> File Name: client.c
	> Author:
	> Mail: 
	> Created Time: 六  3/28 14:51:21 2020
 ************************************************************************/


#include "head.h"
#include "tcp_client.h"

int main(int argc, char **argv) {
    char msg[512] = {0};
    int sockfd;
    if (argc != 4) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        return 1;
    }

    if ((sockfd = socket_connect_timeout(argv[1], atoi(argv[2]), atoi(argv[3]))) < 0) {
        perror("socket_connect");
        return 2;
    }
    printf("Connected!\n");
    sleep(60);
    close(sockfd);
    return 0;
} 

```

## `SocketProject/server/backup`

### 使用`poll`实现`echo`服务器

```c
/*************************************************************************
	> File Name: poll_echo
	> Author:
	> Mail: 
	> Created Time: Tue 07 Apr 2020 06:40:01 PM CST
 ************************************************************************/

#include "../common/color.h"
#include "../common/common.h"
#include "../common/tcp_server.h"
#include "../common/head.h"

#define POLLSIZE 10
#define BUFSIZE 512

char ch_char(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return  c;
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }
    int server_listen, fd;
    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_create");
        exit(1);
    }
    
    struct pollfd event_set[POLLSIZE];

    for (int i = 0; i < POLLSIZE; i++) {
        event_set[i].fd = -1;
    }
    event_set[0].fd = server_listen;
    event_set[0].events = POLLIN;

    while (1) {
        int retval;
        if ((retval = poll(event_set, POLLSIZE, -1)) < 0) {
            perror("poll");
            return 1;
        }
        if (event_set[0].revents & POLLIN) {
            if ((fd = accept(server_listen, NULL, NULL)) < 0) {
                perror("accept");
                continue;
            }
            retval--;
            int i;
            for (i = 1; i < POLLSIZE; i++) {
                if (event_set[i].fd < 0) {
                    event_set[i].fd = fd;
                    event_set[i].events = POLLIN;
                    break;
                }
            }
            if (i == POLLSIZE) {
                printf("Too many clients!\n");
                close(fd);
            }
        }
        for (int i = 1; i < POLLSIZE; i++) {
            if (event_set[i].fd < 0) continue;
            if (event_set[i].revents & (POLLIN | POLLHUP | POLLERR)) {
                retval--;
                char buff[BUFSIZE] = {0};
                if (recv(event_set[i].fd, buff, BUFSIZE, 0) > 0) {
                    printf("Recv: %s \n", buff);
                    for (int i = 0; i < strlen(buff); i++) {
                        buff[i] = ch_char(buff[i]);
                    }
                    send(event_set[i].fd, buff, strlen(buff), 0);
                } else {
                    close(event_set[i].fd);
                    event_set[i].fd = -1;
                }
            }
            if (retval <= 0) break;
        }
    } 
    return 0;
} 

```

### 使用`epoll`实现`echo`服务器

```c
/*************************************************************************
	> File Name: epoll_echo.c
	> Author:
	> Mail:
	> Created Time: Sat 11 Apr 2020 08:24:48 PM CST
 ************************************************************************/
#include <sys/epoll.h>
#define MAX_EVENTS 10
#include "../common/head.h"
#include "../common/tcp_server.h"
#include "../common/common.h"
#define BUFFSIZE 512

int main(int argc, char **argv) {
    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, nfds, epollfd;
    char buff[BUFFSIZE] = {0};
    if (argc != 2) exit(1);
    listen_sock = socket_create(atoi(argv[1]));
/* Code to set up listening socket, 'listen_sock',
   (socket(), bind(), listen()) omitted */
    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                conn_sock = accept(listen_sock, NULL, NULL);
                if (conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                make_nonblock(conn_sock);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;

                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                //do_use_fd(events[n].data.fd);
                if (events[n].events & (EPOLLIN | EPOLLHUP | EPOLLERR)) {
                    memset(buff, 0, sizeof(buff));
                    if (recv(events[n].data.fd, buff, BUFFSIZE, 0) > 0) {
                        printf("recv: %s", buff);
                        for (int i = 0; i < strlen(buff); i++) {
                            if (buff[i] >= 'a' && buff[i] <= 'z') buff[i] -= 32;
                        }
                        send(events[n].data.fd, buff, strlen(buff), 0);
                    } else {
                        if (epoll_ctl(epollfd, EPOLL_CTL_DEL, events[n].data.fd, NULL) < 0) {
                            perror("epoll_ctrl");
                        }
                        close(events[n].data.fd);
                        printf("Logout!\n");
                    }
                }
            }
        }
    }
return 0;
}

```

### `thread_poll_echo.c`

```c
/*************************************************************************
	> File Name:
	> Author:
	> Mail: 
	> Created Time: Tue 07 Apr 2020 06:40:01 PM CST
 ************************************************************************/

#include "../common/color.h"
#include "../common/common.h"
#include "../common/tcp_server.h"
#include "../common/head.h"

#define MAXTASK 100
#define MAXTHREAD 20

char ch_char(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return  c;
}


void do_echo(int fd){
    char buf[512] = {0}, ch;
    int ind = 0;
    while (1) {
        if (recv(fd, &ch, 1, 0) <= 0) {
            break;
        }
        if (ind < sizeof(buf)) {
            buf[ind++] = ch_char(ch);
        }
        if (ch == '\n') {
            send(fd, buf, ind, 0);
            ind = 0;
            continue;
        }
    }
}


typedef struct {
    int sum;
    int *fd;
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}TaskQueue;

void TaskQueueInit(TaskQueue *queue, int sum) {
    queue->sum = sum;
    queue->fd = calloc(sum, sizeof(int));
    queue->head = queue->tail = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

void TaskQueuePush(TaskQueue *queue, int fd) {
    pthread_mutex_lock(&queue->mutex);
    queue->fd[queue->tail] = fd;
    printf(GREEN"<TaskPush> "NONE": %d \n", fd);
    if (++queue->tail == queue->sum) {
        printf(RED"<QueueEnd> "NONE": %d \n", fd);
        queue->tail = 0;
    }
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
}

int TaskQueuePop(TaskQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    while (queue->tail == queue->head) 
        pthread_cond_wait(&queue->cond, &queue->mutex);
    int fd = queue->fd[queue->head];
    printf(GREEN"<TaskPop> "NONE": %d \n", fd);
    if (++queue->head == queue->sum) { 
        printf(RED"<QueueEnd> "NONE": %d \n", fd);
        queue->head = 0;
    }
    pthread_mutex_unlock(&queue->mutex);
    return fd;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);

    TaskQueue *queue = (TaskQueue *)arg;
    while (1) {
        int fd = TaskQueuePop(queue);
        do_echo(fd);
    }
}

int main(int argc, char **argv){
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }
    int port, server_listen, fd;
    port = atoi(argv[1]);

    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    TaskQueue queue;
    TaskQueueInit(&queue, MAXTASK);
    pthread_t *tid = (pthread_t *)calloc(MAXTHREAD, sizeof(pthread_t));

    for (int i = 0; i < MAXTHREAD; i++) {
        pthread_create(&tid[i], NULL, thread_run, (void *)&queue);
    }

    while (1)  {
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
        printf(BLUE"<Login> "NONE": %d \n", fd);
        TaskQueuePush(&queue, fd);
    }

    return 0;
}

```

### 使用select实现echo服务器

```c
/*************************************************************************
	> File Name: select_echo
	> Author: zhangfengbo
	> Mail:1819067326@qq.com 
	> Created Time: 2020年04月16日 星期四 09时07分53秒
 ************************************************************************/
#include "../common/color.h"
#include "../common/common.h"
#include "../common/tcp_server.h"
#include "../common/head.h"

#define CLIENTSIZE 50
#define BUFFERSIZE 512

char ch_char(char c) {
    if(c >= 'a' && c <= 'z') 
    return c - 32;
    return c;
}

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, " usage :%s port !\n", argv[0]);
        exit(1);
    }
    int server_listen, sockfd, max_fd;
    int client[CLIENTSIZE] = {0};
    memset(client, -1, sizeof(client));
    if((server_listen = socket_create(atoi(argv[1]))) <  0) {
        perror("socket_create");
        exit(1);
    }
    make_nonblock(server_listen);//转换为非阻塞状态
    fd_set rfds, wfds, efds;
    max_fd = server_listen;

    while(1) {
        FD_ZERO(&rfds);
        FD_ZERO(&wfds);
        FD_ZERO(&efds);

        FD_SET(server_listen, &rfds);

        for(int i = 0 ; i < CLIENTSIZE; i++){
            if(client[i] == server_listen){
                continue;
            }
            if(client[i] > 0) {//有效的文件描述符
                if(max_fd < client[i]) max_fd = client[i];
                FD_SET(client[i], &rfds);
            }
        }

        if(select(max_fd + 1, &rfds, NULL, NULL, NULL) < 0){
            perror("select");
            return 1;
        }
        int fd;
        if(FD_ISSET(server_listen, &rfds)) {
            printf("connect ready on server_listen!\n");
            if((fd = accept(server_listen, NULL, NULL)) < 0){
                perror("accept");
                return 1;
            }
            if(sockfd > CLIENTSIZE){
                printf("too many clients!\n");
                close(sockfd);
            }else{
                make_nonblock(sockfd);
                if(client[sockfd] == -1)
                client[sockfd] = sockfd;
            }
        }

        for(int i = 0; i < CLIENTSIZE; i++) {
            if(i == server_listen) continue;
            if(FD_ISSET(i, &rfds)) {
                char buffer[BUFFERSIZE] = {0};
                int retval = recv(i ,buffer, BUFFERSIZE, 0);
                if(retval <= 0){
                    printf("logout!\n");
                    client[i] = -1;
                    close(1);
                    continue;
                }
                printf("recev : %s", buffer);
                for(int j = 0; j < strlen(buffer); j++) {
                    buffer[j] = ch_char(buffer[j]);
                }
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }
    
    return 0;
}

```

## `SocketProject/filetransfer`

### 发送`sender.c`

```c
/*************************************************************************
	> File Name: sender.c
	> Author:
	> Mail: 
	> Created Time: Thu 02 Apr 2020 06:39:54 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/tcp_client.h"
#include "./common/common.h"

struct FileMsg{
    long size;
    char name[50];
    char buf[4096];
};

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
        return 1;
    }

    int sockfd, port;
    char buff[100] = {0};
    char name[50] = {0};
    struct FileMsg filemsg;

    port = atoi(argv[2]);
    if ((sockfd = socket_connect(argv[1], port)) < 0) {
        perror("socket_connect");
        return 1;
    }
    
    while (1) {
        scanf("%[^\n]s", buff);
        getchar();
        if (!strncmp("send ", buff, 5)) {
            strcpy(name, buff + 5);
        } else {
            fprintf(stderr, "invalid command!\n");
            continue;
        }
        FILE *fp = NULL;
        size_t size;
        if ((fp = fopen(name, "rb")) == NULL) {
            perror("fopen");
            continue;
        }
        fseek(fp, 0L, SEEK_END);
        filemsg.size = ftell(fp);
        strcpy(filemsg.name, name);
        fseek(fp, 0L, SEEK_SET);
        while ((size = fread(filemsg.buf, 1, 4096, fp))) {
            send(sockfd, (void *)&filemsg, sizeof(filemsg), 0);
            memset(filemsg.buf, 0, sizeof(filemsg.buf));
        }
        printf("After Send!\n");
    }
    close(sockfd);
    return 0;
}

```

### 收`recver.c`



```c
/*************************************************************************
	> File Name: recver.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Apr 2020 07:07:22 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/tcp_server.h"
#include "./common/common.h"

struct FileMsg{
        long size;
        char name[50];
        char buf[4096];

};
void signal_process(int sig) {
    wait(NULL);
}


void child_do(int fd) {
    size_t recv_size, size = 0;
    struct FileMsg packet_t, packet, packet_pre;
    int packet_size = sizeof(struct FileMsg);
    int offset = 0, flag = 0, cnt = 0;
    long filesize;
    printf("Before recv!\n");
    FILE *fp = NULL;
    while (1) {
        if (flag) {
            memcpy(&packet, &packet_pre, flag);
            offset = flag;
        }
        flag = 0;
        while ((recv_size = recv(fd, (void *)&packet_t, packet_size, 0)) > 0) {
            if (offset + recv_size == packet_size) {
                memcpy((char *)&packet + offset, &packet_t, recv_size);
                offset = 0;
                printf("整包 size = %d!\n", packet_size);
                break;
            } else if (offset + recv_size < packet_size) {
                memcpy((char *)&packet + offset, &packet_t, recv_size);
                printf("拆包 size = %ld!\n", offset + recv_size);
                offset += recv_size;
            } else {
                memcpy((char *)&packet + offset, &packet_t, packet_size - offset);
                flag = recv_size - (packet_size - offset);
                memcpy(&packet_pre, (char *)&packet_t + packet_size - offset, flag);
                printf("粘包 size = %d!\n", flag);
                offset = 0;
                break;
            }
        }
        if (!cnt) {
            printf("recv %s with size = %d \n", packet.name, packet_size);
            char t_name[100] = {0};
            sprintf(t_name, "./data/%s", packet.name);
            if ((fp = fopen(t_name, "wb")) == NULL) {
                perror("fopen");
                break;
            }
        }
        cnt++;
        size_t write_size;
        if (packet.size - size >= sizeof(packet.buf)) {
            write_size = fwrite(packet.buf, 1, sizeof(packet.buf), fp);
        } else {
            write_size = fwrite(packet.buf, 1, packet.size - size, fp);
        }
        size += write_size;
        if (size >= packet.size) {
            printf("Finish!\n");
            break;
        }
    }
    close(fd);
    fclose(fp);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        return 1;
    }
    int server_listen, port, fd;
    pid_t pid;
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        return 1;
    }

    signal(SIGCHLD, signal_process);
    while (1) {
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            continue;
        }
        printf("After accept\n");
        if ((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if (pid == 0) {
            close(server_listen);
            child_do(fd);
            //child
            exit(0);
        } else {
            //parent
            close(fd);
        }
    }

    return 0;
}

```

## `SocketProject/tcp_damon`

### `test_o_non_block.c`

```c
/*************************************************************************
	> File Name: test_o_non_block.c
	> Author:
	> Mail: 
	> Created Time: 日  3/29 14:13:10 2020
 ************************************************************************/

#include "../common/head.h"

int main () {
    printf("%d\n",O_CREAT);
}

```