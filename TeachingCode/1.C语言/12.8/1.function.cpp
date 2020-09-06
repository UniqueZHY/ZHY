/*************************************************************************
	> File Name: 1.function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 16时26分05秒
 ************************************************************************/
#include<stdio.h>

int funcA(int);//funcA的声明
int funcB(int);

int main() {
    funcA(6);
    funcB(6);
    return 0;
}

int funcB(int n) {
    printf("funcB :%d\n", n);
    if (n == 0) return 0;
    funcA(n - 1);
    return n;
}

int funcA(int n) {
    printf("funcA: %d\n", n);
    if (n == 0) return 0;
    funcB(n - 1);
    return n;
}
