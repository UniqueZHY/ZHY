/*************************************************************************
	> File Name: z.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月19日 星期四 14时12分55秒
 ************************************************************************/
#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <dirent.h>
#include  <string.h>
#include  <linux/limits.h>
#include  <pwd.h>
#include  <grp.h>
#include  <time.h>

#define  PARAM_NONE  0
#define  PARAM_A  1
#define  PARAM_L  2
#define  MAXROWLEN  80
int  g_leave_len  =  MAXROWLEN;
int  g_maxlen;
//错误打印函数
void  my_error(const  char*  errstring,  int  line) {
    fprintf(stderr,"line:%d",line);
    perror(errstring);
    exit(1);
}

void  display_single(char  *name) {
    int i, len;
    if(g_leave_len  <  g_maxlen){
        printf("\n");
        g_leave_len  =  MAXROWLEN;//如果剩下的地方不够了，就换行        
    }        
    len  =  strlen(name);
    len  =  g_maxlen  -  len;
    printf("%-s",name);
    for(i=0;i<len;i++)  {
        printf("  ");        
    }
    printf("  ");
    g_leave_len  =  g_leave_len  -  g_maxlen - 5;//文件之间的间隔
}

void  display_attribute(struct  stat  buf,  char  *name) {//权限
    char  buf_time[32];
    struct  passwd  *psd;//从该结构体获取文件所有者的用户名
    struct  group  *grp;//从该结构体获取文件所有者所属组的组名
    //获取 打印文件类型
    if(S_ISLNK(buf.st_mode))  printf("l");
    else  if(S_ISREG(buf.st_mode))//S_ISREG 普通文件
        printf("-");
    else  if(S_ISDIR(buf.st_mode))//S_ISDIR目录文件
        printf("d");
    else  if(S_ISCHR(buf.st_mode))//S_ISCHR字符特殊文件
        printf("c");
    else  if(S_ISBLK(buf.st_mode))//S_ISBLK 块特殊文件
        printf("b");
    else  if(S_ISFIFO(buf.st_mode))//S_ISFIFO管道
        printf("f");
    else  if(S_ISSOCK(buf.st_mode))//S_ISSOCK 套接字
        printf("s");
    //获取 打印文件所有者权限
    if(buf.st_mode  &  S_IRUSR)//S_IRUSR 用户读
        printf("r");
    else
        printf("-");
    if(buf.st_mode  &  S_IWUSR)//S_IWUSR 用户写
        printf("w");
    else
        printf("-");
    if(buf.st_mode  &  S_IXUSR)//S_IXUSR 用户执行
        printf("x");
    else
        printf("-");
    //获取 打印文件所有者同组用户对该文件的权限
    if(buf.st_mode  &  S_IRGRP)//S_IRGRP 组读
        printf("r");
    else
        printf("-");
    if(buf.st_mode  &  S_IWGRP)//S_IWGRP 组写
        printf("w");
    else
        printf("-");
    if(buf.st_mode  &  S_IXGRP)//S_IXGRP 组执行  
        printf("x");
    else
        printf("-");
    //获取 打印其他用户对该文件的操作权限
    if(buf.st_mode  &  S_IROTH)//S_IROTH  其他读
        printf("r");
    else
        printf("-");
    if(buf.st_mode  &  S_IWOTH)//S_IWOTH 其他写
        printf("w");
    else
        printf("-");
    if(buf.st_mode  &  S_IXOTH)//S_ICOTH其他执行   
        printf("x");
    else
        printf("-");
    printf("    ");
    //根据uid 与gid获取文件所有者的用户名和组名
    psd  =  getpwuid(buf.st_uid);
    grp  =  getgrgid(buf.st_gid);
    printf("%4d",buf.st_nlink);//打印文件的链接数
    printf("%-8s",psd->pw_name);
    printf("%-9s",grp->gr_name);
    printf("%6d",buf.st_size);//打印文件大小                                      
    printf("%6d",buf.st_size);
    strcpy(buf_time,  ctime(&buf.st_mtime));
    buf_time[strlen(buf_time)  -  1]  =  '\0';//取掉换行符
    printf("  %s",buf_time);//打印文件的时间信息
}

void  display(int  flag,char  *pathname) {
    int  i,j;
    struct  stat  buf;
    char  name[NAME_MAX  +  1];
    for(i=0,j=0;i<strlen(pathname);i++){
        if(pathname[i]  ==  '/') {
            j = 0;
        } else {
            name[j++]  =  pathname[i];
        }
    }
    name[j]  =  '\0';
    if(lstat(pathname,&buf)  ==  -1){
        my_error("stat",__LINE__);        
    }
    if(flag  ==  PARAM_NONE){
        if(name[0]  !=  '.'){
            display_single(name);
        }
    } else  if(flag  ==  PARAM_A) {
        display_single(name);              
    } else if(flag == PARAM_L) {//-l
        if(name[0] != '.') {//隐藏文件
            display_attribute(buf,name);
            printf(" %-s\n",name);                    
        }    
    } else if(flag == (PARAM_A)) {//-a
        display_attribute(buf,name);
        printf(" %-s\n",name);    
    }
}

void display_dir(int flag_param,const char *path) {
    DIR* dir;
    struct dirent* dirent;
    char filenames[256][PATH_MAX+1],temp[PATH_MAX+1];
    int count = 0;
    if((dir = opendir(path)) == NULL){
        //opendir打开目录， 函数原型 DIR *opendir(const char *name)返回DIR*类的目录流 
        my_error("opendir",__LINE__);    
    }
    //找到名字最长文件名
    while((dirent = readdir(dir)) != NULL){
        if(g_maxlen < strlen(dirent->d_name)) {
            g_maxlen = strlen(dirent->d_name);
        } 
        count++;    
    }
    closedir(dir);
//int closedir(DIR *dirp) 参数是opendir返回的目录流 成功0   
    if(count>256)
        my_error("文件太多超过了256个",__LINE__);    
    int i,j,len = strlen(path);
    dir = opendir(path);//获取该目录下所有的文件名
    for(i=0;i<count;i++){
        dirent = readdir(dir);
//struct dir *readdir(adir *dirp)参数是opendir返回的目录流
        if(dirent == NULL){
            my_error("readdir",__LINE__);            
        }
        strncpy(filenames[i],path,len);
        filenames[i][len] = 0;
        strcat(filenames[i],dirent->d_name);
        filenames[i][len+strlen(dirent->d_name)] = 0;    
    }
    //按字母序排序
    for(i=0;i<count-1;i++)
        for(j=i+1;j<count-1;j++){
            if(strcmp(filenames[i],filenames[j]) > 0){
                strcpy(temp,filenames[j]);
                strcpy(filenames[j] , filenames[i]);
                strcpy(filenames[i] , temp);        
            }    
        }
    for(i=0;i<count;i++)
        display(flag_param,filenames[i]);
    closedir(dir);
    //没有-l
    if((flag_param & PARAM_L) == 0)
        printf("\n");
}

int main (int argc, char **argv) {
    int i, j, k;
    int num;
    char path[PATH_MAX + 1];
    char param[32];//保存命令行参数，目标文件和目录名不在此例
    int flag_param = PARAM_NONE;//参数种类
    struct stat buf;
    
    j = 0;
    num = 0;
    for(i=1;i<argc;i++){
        if(argv[i][0] == '-'){
            for(k=1;k<strlen(argv[i]);k++){
                param[j] = argv[i][k];
                j++;                            
            }
            num++;        
        }   
    }
    for(i=0;i<j;i++){
        if(param[i] == 'a'){
            flag_param |= PARAM_A;        
        } else if(param[i] == 'l') {
            flag_param |= PARAM_L;         
        } else {
            printf("错误的参数：%c\n",param[i]);
            exit(1);                    
        }   
    }
    param[j] = '\0';
    //如果没输入就显示当前目录
    if((num + 1) == argc){
        strcpy(path,"./");
        path[2] = '\0';
        display_dir(flag_param,path);
        return 0;            
    }
    i = 1;
    for(i=1;i<argc;i++){
        if(argv[i][0] != '-'){
            strcpy(path,argv[i]);
            if(stat(path,&buf) == -1) {
                my_error("stat",__LINE__);
            }    
            if(S_ISDIR(buf.st_mode)) {
                if(path[strlen(argv[i]) - 1] != '/') {//如果最后一个参数不是/就加一个
                    path[strlen(argv[i])] = '/';
                    path[strlen(argv[i] + 1)] = '\0';                 
                } else {
                    path[strlen(argv[i])] = '\0';         
                }
                display_dir(flag_param,path);
            } else {
                display(flag_param, path);
            }
        }
    }
    return 0;
}
