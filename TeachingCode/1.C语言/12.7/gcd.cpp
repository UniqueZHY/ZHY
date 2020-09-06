/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 18时35分45秒
 ************************************************************************/

#include<stdio.h>

int gcd (int a, int b) {
    //if (!b) return a;
    //return gcd(b, a % b);
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
