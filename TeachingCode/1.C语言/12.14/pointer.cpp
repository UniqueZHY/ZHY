/*************************************************************************
	> File Name: pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月14日 星期六 20时31分19秒
 ************************************************************************/
 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*#define offset(T, a) ({\
    T tmp;\
    (char *)&tmp.a - (char *)&tmp;\
})*/
#define offset(T, a) (long)(&(((T *)(NULL))->a))//将空地址转化成T类型，再取地址，间接指向a
#define pchar char *

typedef char *ppchar;
struct Data {
    double a;
    int b;
    char c;
};

void out_put_main(int argc, char *argv[], char *env[]) {
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for(int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);
        if (strncmp(env[i], "USER=", 5) == 0) {
            if (strncmp(env[i] + 5, "unique", 8)) {
                printf("u r not beautiful!\n");
                exit(0);//结束
            }
        }
    }
    return ;
}
 int main(int argc, char *argv[], char *env[]) {
     int num1 = 0x616263;//(61) = 97 = a (62) = 98
     int num2 = 0x61626364;
     pchar p1, p2;
     ppchar p3, p4;
     printf("sizeof(p1) = %lu, sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
     printf("sizeof(p3) = %lu, sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
     printf("%s\n", (char *)(&num1));
     printf("%s\n", (char *)(&num2));
     printf("%s\n", (char *)(&num2 + 1));
     //存储空间在栈区，由高地址位向低地址存储
     printf("%ld\n", offset(struct Data, a));
     printf("%ld\n", offset(struct Data, b));
     printf("%ld\n", offset(struct Data, c));
     out_put_main(argc, argv, env);
     return 0;
 }
