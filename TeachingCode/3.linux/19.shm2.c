/*************************************************************************
	> File Name: 19.shm2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 20时47分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        while (1) {
            //close(pipefd[0]);//同下
            scanf("%[^\n]s", buff);
            getchar();
            write(pipefd[1], buff, strlen(buff));
        }
    } else {
        while (1) {
            //close(pipefd[1]);//可加可不加
            read(pipefd[0], buff, 1024);
            printf("server : %s\n", buff);
            memset(buff, 0, sizeof(buff));
        }
    }

    return 0;
}
