/*************************************************************************
	> File Name: ep10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 18时48分18秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 2000000
int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    long long  sum = 0;
    for(int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    printf("%lld\n", sum);
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 2000000
long long  prime[max_n + 5] = {0};

void f() {
    for (long long  i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (long long j = i * i; j <= max_n; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}
int main() {
    f();
    long long  ans = 0;
    for (long long i = 1; i <= prime[0] ; i++) {
        ans += prime[i];
    //    if (prime[i] <= 100) cout << prime[i] << endl;
    }
    cout << ans << endl;
    return 0;
}

