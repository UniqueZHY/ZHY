/*************************************************************************
	> File Name: ep24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 19时44分32秒
 *****************************************/
#include<iostream>
using namespace std;
#define N 10

int fac[N + 5] = {0};
int num[N + 5] = {0};//是否移动, 过没移动为1

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for(int i = 1;i <= n; i++) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return ;
}

int get_num(int k, int n, int &x) {
    int step = k / n;
    x = 0;
    for(int t = 0; t <= step; x +=(t <= step)) {
        t += num[x];
    }
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(N);
    int k = 1000000 - 1;//还有剩余多少次全排列
    for(int i = N; i > 0; i--) {
        int x;
        k = get_num(k, fac[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;

}

