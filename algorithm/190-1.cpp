/*************************************************************************
	> File Name: 190-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 19时46分52秒
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
int is_prime[max_n + 5] = {1, 1, 0};
void xian() {
    for (int i = 2; i * 2 <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    xian();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i * 2 <= n; i++) {
        if (is_prime[i] == 0 && is_prime[n - i] == 0)
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
