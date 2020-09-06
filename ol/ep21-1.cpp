/*************************************************************************
	> File Name: ep21-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月01日 星期三 15时11分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 10000

int f[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) f[i] += j;
        }
    }
    return ;
}

int main() {
    init();
    long long sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (f[i] != i && f[i] < max_n && i == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
