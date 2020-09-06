/*************************************************************************
	> File Name: 9.2.fork.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 16时54分52秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;
    printf("before fork()...");
    if ((pid = fork()) < 0) {
        perror("fork");
    }
    if (pid == 0) {
        printf("\nIn Child!\n");
    } else {
        sleep(1);
        printf("\nIn Parent!\n");
    }
    printf("End Fork!\n");
    return 0;
}
/*输出结果：
before fork()...
In Child!
End Fork!
before fork()...
In Parent!
End Fork!
*/

//原因：
//printf底层是write
//是因为printf在输出时将输出结果存放到缓存区了，并且还没有 \n ，会等待继续输出
//fork在执行的时候会复制两份
//24行不管是子进程还是父进程都会执行，所以输出两分
//14行

//before fork输出一次的解决方案：
//1. 将输出before fork 后边加换行
//2. 将fflush(stdout);刷新缓冲区
