/*************************************************************************
	> File Name: union.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月14日 星期六 19时09分12秒
 ************************************************************************/

#include<stdio.h>

union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int is_little() {
    int x = 1;
    return ((char *)(&x))[0];//转换成字符串的首地址,在取地0位
}

int main() {
    printf("%d\n", is_little());
    union IP p;
    char str[20];
    int arr[4];
    while(~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2,arr + 3);
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        printf("%d\n", p.num);
    }
    return 0;
}
