/*************************************************************************
	> File Name: 15.shm.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时10分21秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid;
    FILE *fp, *fp1;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if ((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    fp = fdopen(pipefd[1], "w");
    fp1 = fdopen(pipefd[0], "r");
    if (pid == 0) {
        while (1) {
            scanf("%[^\n]s", buff);
            getchar();
            fprintf(fp, "%s\n", buff);
            //fprintf(fp,"%s", buff);//存到一定数量再输出；
            //子进程输入，父进程输出
            fflush(fp);
        }
    } else {
        while (1) {
            fscanf(fp1, "%s", buff);
            printf("server : %s\n", buff);
        }
    }

    return 0;
}
