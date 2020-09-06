/*************************************************************************
	> File Name: 21.popen.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月11日 星期六 13时09分57秒
 ************************************************************************/

#include <stdio.h>
#include<unistd.h>
#include<string.h>

int main() { 
    FILE *fp = NULL; 
    FILE *fh = NULL; 
    char buff[1024] = {0};   
    memset(buff, 0, sizeof(buff)); 
    fp = popen("ls -al","r");//将命令ls-l同过管道读到fp 
    fh = fopen("99.c","w");// 创建一个可写的文件 
    fread(buff, 1024, 1, fp);//将fp的数据流读到buff中 
    fwrite(buff, 1024, 1, fh);//将buff的数据写入fh指向的文件中   
    pclose(fp);
    fclose(fh);
    return 0;   
} 
