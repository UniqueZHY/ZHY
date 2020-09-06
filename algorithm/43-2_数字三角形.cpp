/*************************************************************************
	> File Name: 43-2_数字三角形.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 20时14分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n ,num[1005][1005], ans[1005][1005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t = max(i, ans[n][i]);
    }
    cout << t << endl;
    return 0;
}
/*
int n ,num[1005][1005], asn[1005][1005];
int main() {
    cin >> n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i + 1][j + 1], ans[i + 1][j]) + num[i][j];
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t = max(y, ans[n][i]);
    }
    cout << ans[1][1] << endl;
    return 0;
}*/
