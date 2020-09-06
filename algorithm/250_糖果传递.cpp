/*************************************************************************
	> File Name: 250_糖果传递.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 19时48分17秒
 ************************************************************************/
//假设每个人的糖果数为a1,a2,a3,a4...an

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1000000
long long  a[MAX_N + 5];
long long  s[MAX_N + 5];//Si=ak累加
long long  g[MAX_N + 5];
//gi=Si-i*c每一个点从第一个点开始调整的代价
long long  n, c, ans, sum = 0;
int main() {
    cin >> n; 
    for (long long  i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n;
    for (long long  i = 1; i <= n; i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    for (long long  i = 1; i <= n; i++) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
