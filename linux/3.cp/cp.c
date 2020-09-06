/*************************************************************************
	> File Name: cp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 15时51分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 512


int main(int argc, char **argv) {
    int fd_in, fd_out;
    //in用来放一个文件的数据out用来给新创建的文件数据
    ssize_t nread;
    char buf[BUFSIZE + 5] = {0};

    if (argc != 3) {
        printf("Usage: %s sourcefile destfile\n", argv[0]);
        exit(1);
    }
    //打开文件，O_RDONLY只为了读打开
    if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }
    //打开文件，如果不存在就创建一个
    if ((fd_out = creat(argv[2], 0644)) == -1) {
        perror(argv[2]);
        exit(1);
    }
    //从fd_in中读BUFSIZE个到buf 中
    while ((nread = read(fd_in, buf, BUFSIZE)) > 0) {
        //把fd_in 中的读到fd_out
        printf("nread = %ld\n", nread);
        int nwrite;
        //将参数buf下所指的内存写入nread个字节到指定文件内
        if ((nwrite = write(fd_out, buf, nread)) != nread) {
            //从buf写到fd_out
        //if ((nwrite = write(fd_out, buf, nread)) != nread){ 
            perror("write");
        }
        //清空buf
        //memset(buf, 0, BUFSIZE + 5);
        printf("nwrite = %d\n", nwrite);
    }

    close(fd_in);
    close(fd_out);
    return 0;
}
