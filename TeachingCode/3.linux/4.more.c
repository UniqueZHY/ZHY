/*************************************************************************
	> File Name: 4.more.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 19时29分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PAGELINE 15
#define LENLINE 512

void do_more(FILE *fp);

int main(int argc, char **argv) {
    FILE *fp;
    if (argc == 1) 
    //printf("Usage: %s [filename | stdin]\n", argv[0]);
        do_more(stdin);
    else {
        while (--argc) {
            if ((fp = fopen(*++argv, "r")) != NULL) {
                do_more(fp);
            }
        }
    }

    return 0;
}

void do_more(FILE *fp) {
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty", "r");
    int num_line = 0, reply, get_cmd(FILE *);
    while (fgets(line, LENLINE, fp)) {
        //文件获取
        if (num_line == PAGELINE) {
            reply = get_cmd(cmd); //接受字符是什么    
            if (reply == 0) break;
            num_line -= reply;
        } 
        //够10行就输出
        if (fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        //从文件流中读
        if (c == 'q') return 0;
        if (c == ' ') return PAGELINE;
        if (c == '\n') return 1;
    }
    return -1;
}
