/*************************************************************************
	> File Name: 390_原木切割.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月29日 星期三 14时05分02秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int func(int len) {
    int cnt = 0;
    for (int i = 0; i < n ; i++) {
        cnt += num[i] / len;
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    int l = 0, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s >= m) l = mid;//1111111000000找最后一个1
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
/*#include<iostream>
#include<cmath>
using namespace std;
#define max_n 100000
typedef long long ll;
ll inf = 200000005;
ll a[max_n];
ll n , m;

int is_val(int x) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += a[i] / x;
    }
    return num >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = inf;
    for (int i = 0; i < 100; i++) {
        ll mid = (l + r) / 2;
        if (is_val(mid)) l = mid;
        else r = mid;
        //cout << mid  << endl;
    }
    cout << l << endl;
    return 0;
}*/
