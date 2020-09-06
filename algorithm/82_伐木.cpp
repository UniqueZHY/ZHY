/*************************************************************************
	> File Name: 82_伐木.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月27日 星期一 17时45分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 1000005
typedef long long ll;
ll a[max_n];
ll n, m, maxx = 0;

bool judge(int x) {
    ll num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x)  num += a[i] - x;
    }
    return num >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maxx) maxx = a[i];
    }
    ll l = 0, r = maxx;
    int ans = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (judge(mid)) {
            l = mid + 1;
            ans = mid;
        } else r = mid;
    }
    cout << ans << endl;
    return 0;
}
