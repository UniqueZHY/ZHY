/*************************************************************************
	> File Name: 188_指定范围内的质数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 19时27分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define  max_n 1000000
int prime[max_n + 5] = {0};
 
 
void init() {
    for (int i = 2; i <= max_n; i++){
        if (!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            else prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}
int main() {
    init();
    int m, n;
    cin >> n >> m;
    for(int i = 1 ; i <= prime[0] && prime[i] <= n; i++) {
        if (prime[i] >= m) 
        cout << prime[i] << endl;
    }
    return 0;
}
