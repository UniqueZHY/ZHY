/*************************************************************************
	> File Name: 10.作业.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 17时31分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>//getpid.ppid
#include <unistd.h>//exec、fork
#include <sched.h>//clone
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid;
    char filename[512] = {0};
    char o_name[512] = {0};
    char f_type[256] = {0};
    char cmd[512] = {0};
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename arg...\n", argv[0]);
        return 1;
    }
    
    strcpy(filename, argv[1]);
    
    //a.c b.cpp

    char *sub;

    sub = strstr(filename, ".");
    strncpy(o_name, filename, sub - filename);
    strcpy(f_type, sub);
    

    if (!strcmp(f_type, ".c")) {
        strcpy(cmd, "gcc");
    } else if (!strcmp(f_type, ".cpp")) {
        strcpy(cmd, "g++");
    } else {
        fprintf(stderr, "Not support file type!\n");
        return 2;
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        return 3;
    }

    if (pid == 0) {
        execlp("vim", "vim", filename, NULL);
    }

    wait(NULL);

    return 0;
}
