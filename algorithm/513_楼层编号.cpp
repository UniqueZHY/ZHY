/*************************************************************************
	> File Name: 513_楼层编号.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 18时23分27秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int solve(int x, int y) {
    int cnt = 0;
    int b = 0;
    while (x) {
        if (x < 10) return (x == y);
        b = x % 10;
        x /= 10;
        if (b == y) return 1;
    }
    return 0;
}

int main() {
    int m, t, ans = 0;
    cin >> m >> t;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += solve(i, t);
    }
    ans = m - sum;
    cout << "sum = " << sum << endl;
    cout << ans << endl;
    return 0;
}
