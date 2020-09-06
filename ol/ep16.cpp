/*************************************************************************
	> File Name: ep16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 15时53分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 400

int ans[max_n + 5] = {1, 1, 0};
int main() {
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j]*=1024;//2^10 = 1024
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (ans[0] == j);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
