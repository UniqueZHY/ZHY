/*************************************************************************
	> File Name: 394_跳石头.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月31日 星期五 19时07分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define max_n 50005
using namespace std;
int l, n, m;
int a[max_n];

int is_val(int x) {
    int cnt = 0, dis = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - dis < x) cnt++;
        else dis = a[i];
    }
    return cnt <= m;
}

int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int left = 0, right = l;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (is_val(mid)) left = mid + 1, ans = mid;
        else right = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
