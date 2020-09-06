/*************************************************************************
	> File Name: more.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 19时29分08秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#define LENLINE 512
//一页多少行
//#define PAGELINE 15
//一行有多长

void do_more(FILE *fp); 

int main(int argc, char **argv) {
    FILE *fp;//文件指针
    //没有选项
    if (argc == 1) 
        do_more(stdin);//标准输入流，文件流指针
    else {
        while (--argc) {
            //如果以读打开了文件不为空
            if ((fp = fopen(*++argv, "r")) != NULL) {
                do_more(fp);
            }
        }
    }
    return 0;
}
//把fp读出来
void do_more(FILE *fp) {
    struct winsize sz;//获取屏幕长度
    ioctl(STDIN_FILENO, TIOCGWINSZ, &sz);
    int P = sz.ws_row;//屏幕宽度
    char line[LENLINE] = {0};
    // /dev/tty在终端上打开一个流
    // cmd用来接受命令
    FILE *cmd = fopen("/dev/tty", "r");
    //reply用来获取响应
    int num_line = 0, reply, get_cmd(FILE *, int x);
    while (fgets(line, LENLINE, fp)) {
        //放在行里面,每次多长,放在哪
        //if (num_line == PAGELINE) {
          if (num_line == P) {
            reply = get_cmd(cmd, P);
            if (reply == 0) break;
            num_line -= reply;
        }
        if (fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
      }

}

int get_cmd(FILE *fp, int P) {
    printf("more:");
    int c;
    //getchar获取一个字符
    //fgetc(fp)从文件流中读
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'q') return 0;
        if (c == ' ') return P;
        if (c == '\n') return 1;
    }
    return -1;
}
