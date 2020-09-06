/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 14时44分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int fac1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * fac1(n - 1);
}

int fac2(int n) {
    return (1 + n) * n / 2;
}

int g(int (*func)(int), int (func2)(int), int x) {
    if (x < 5) return func(x);
    else return func2(x);
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("f(%d) = %d\n", n, g(fac1, fac2, n));
    }
    return 0;
}
