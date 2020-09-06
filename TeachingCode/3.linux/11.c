/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 18时06分28秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        exit(1);
    }
    char name[20];
    strcpy(name, argv[1]);
    FILE *fp;
    int len = strlen(name);
    char last;
    last = name[len - 1];
    //printf("%c", last);
    pid_t pid, pid1, pid2;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    } else if (pid == 0) {
        if ((fp = fopen(name, "r")) == NULL) {
            execlp("vim", "vim", name, NULL);
        }
    } else {
        pid2 = wait(NULL);
        if ((pid1 = fork()) < 0) {
            perror("fork()");
            exit(1);
        } else if (pid1 == 0) {
            if (last == 'c') execlp("gcc", "gcc", name, NULL);
            else if (last == 'p') execlp("g++", "g++", name, NULL);
            else exit(1);
        } else {
            pid2 = wait(NULL);
            execlp("./a.out", "./a.out", name, NULL);
        }
    }
    return 0;
}
