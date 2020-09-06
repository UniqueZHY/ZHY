/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 12时26分08秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

int main() {
    FILE *f = fopen("./a.txt", "r");
    flock(f->_fileno, LOCK_EX);
    printf("After flock()!\n");
    sleep(10);
    return 0;
}
