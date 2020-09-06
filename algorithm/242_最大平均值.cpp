/*************************************************************************
	> File Name: 242_最大平均值.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 16时34分11秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 100000
#define INF  0x3f3f3f3f
long long a[MAX_N + 5];
long long b[MAX_N + 5];
long long sum[MAX_N + 5];
long long n, m;

bool check(long long A) {
    ///(ai+1 + ai+2 + ai+3 +...+ai+l) / l >= A
    //(ai+1 + ai+2 + ai+3 +...+ai+l) >= A*l
    //数组b[i] = a[i] - A 即
    //bi+1 + bi+2 + bi+3 +...bi+l >= 0
    
    for (long long i = 1; i <= n; i++) {
        b[i] = a[i] - A;
        sum[i] = b[i] + sum[i - 1];
    }
    long long Y = 0;//i-1之前的最小阴影面积
    for (long long j = m; j <= n; j++) {//序列长度大于等于m,所以算应该从m开始
        Y = min(Y, sum[j - m]);
        if (sum[j] - Y >= 0) return true;
        //用当前值减去分和条件范围内的最小值
        //要求序列长度>=m，即以当前值i为末尾的序列头至少zai i-m的位置,而序列长度可表示为Si-min(0, i-m)即可得到序列和最长长度
    }
    return false;
}

long long bs(long long l, long long r) {
    //二分最大平均值
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main() {
    cin >> n >> m;
    long long l = INF, r = -INF;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    cout << bs(l, r) << endl;
    return 0;
}
