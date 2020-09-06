/*************************************************************************
	> File Name: 79_大输出素数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 23时39分19秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define max_n 10000000
using namespace std;
long long prime[max_n + 5] = {0};
void init() {
    for (long long i = 2; i < max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (long long j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    long long a, b;
    init();
    //cin >> a >> b;
    scanf("%lld%lld", &a, &b);
    for (long long i = 1; prime[i] <= b && i <= prime[0]; i++) {
        if(prime[i] >= a) {
            printf("%lld\n", prime[i]);
        }
    }

    return 0;
}
