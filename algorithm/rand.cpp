/*************************************************************************
	> File Name: rand.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月10日 星期五 20时33分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int f1(int n) {
    return n * 2;
}

int f2(int n) {
    return n * n + 3;
}

int f3(int n) {
    return n >> 1;
}

int (*f[3])(int) = {
    f1, f2, f3
};

int main() {
    srand(time(0));
    int n;
    scanf("%d", &n);
    printf("%d\n", f[rand() % 3](n));
    return 0;
}
