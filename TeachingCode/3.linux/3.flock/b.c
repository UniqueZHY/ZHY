/*************************************************************************
	> File Name: b.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 12时30分18秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

int main() {
    FILE *f = fopen("./a.txt", "r");
    //加上就会等10秒，不加也没关系
    //flock()是君子协议，不加就是硬闯
    flock(f->_fileno, LOCK_EX);
    printf("in b: After flock()!\n");
    return 0;
}

