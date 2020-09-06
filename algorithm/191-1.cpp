/*************************************************************************
	> File Name: 191-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 20时20分04秒
 ************************************************************************/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 8000000
int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break; 
        }
    }
    return ;
}

void solve(int n, int m) {
    int a = -1, b = -1, c = -1, d = -1;
    //a,b最近相邻素数对的下标，c,d最远
    int max_len = 0, min_len = max_n;
    for (int i = 2; i <= prime[0] && prime[i] <= m; i++) {
        if (prime[i - 1] < n) continue;
        int tmp = prime[i] - prime[i - 1];
        if (tmp < min_len) {
            a = prime[i - 1];
            b = prime[i];
            min_len = tmp;
        }
        if (tmp > max_len) {
            c = prime[i - 1];
            d = prime[i];
            max_len = tmp;
        }
    }
    if (a == -1) {
        printf("There are no adjacent primes.\n");
    } else {
        printf("%d, %d are closest, %d,%d are are most distant.\n", a, b, c, d);
    }
}
 
int main() {
    init();
    int n, m;
    while (~scanf("%d %d", &n, &m)) solve(n, m);
    return 0;
}



