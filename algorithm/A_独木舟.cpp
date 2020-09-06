/*************************************************************************
	> File Name: A_独木舟.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 18时26分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 30000
int a[max_n + 5];
int w, n;

int solve(int w, int n) {
    int cnt = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (a[l] + a[r] <= w) {
            cnt++;
            l++;
            r--;
        } else {
            if (a[l] > a[r]) {
                l++,cnt++;
            } else {
                r--, cnt++;
            }
            cnt++;
            if (a[l] == a[r]) {
                l++, r--, cnt += 2;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> w >> n;
    for (int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans;
    ans = solve(w, n);
    cout << ans;

    return 0;
}
