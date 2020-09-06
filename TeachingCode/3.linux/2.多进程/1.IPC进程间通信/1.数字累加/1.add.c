/*************************************************************************
	> File Name: 14.add.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 16时12分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

//定义两个文件
char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Num {
    int now;
    int sum;
};

size_t get_num(struct Num *num) {
    size_t read;
    FILE *f = fopen(num_file, "r");//打开文件
    //打开失败
    if (f == NULL) {
        perror("fopen");
        return -1;
    }
    //读文件数据
    if ((read = fread(num, sizeof(struct Num), 1, f)) < 0) {
        return -1;
    }
    fclose(f);
    //printf("       write %d \n", read);
    return read;
}

size_t set_num(struct Num *num) {
    FILE *f = fopen(num_file, "wb");
    size_t write = fwrite(num, sizeof(struct Num), 1, f);
    fclose(f);
    //printf("       write %d \n", write);
    return write;
}

void do_add(int max, int x) {
    struct Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        //加了互斥锁
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        printf("<%d> : %d   %d  \n", x, num.now, num.sum);
        if (num.now > max) {
            break;
        }
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s max ins\n", argv[0]);
        return 1;
    }
    int x = 0;
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    pid_t pid;
    struct Num num;
    num.now = 0;
    num.sum = 0;
    set_num(&num);

    for (int i = 0; i < ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            x = i; //进程编号
            break;
        }
    }
    
    if (pid == 0) {
        do_add(max, x); //子进程
        printf("<%d> exit!\n", x);
        exit(0);
    }
    while (ins) {
        wait(NULL); //等子进程销毁
        ins--;
    }
    get_num(&num);
    printf("Ans = %d\n", num.sum);
    return 0;
}
