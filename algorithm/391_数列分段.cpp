/*************************************************************************
	> File Name: 391_数列分段.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月01日 星期六 18时01分30秒
 ************************************************************************/
#include <iostream>
using namespace std;
typedef long long ll;

ll n, m, num[100005], mmax, x;

ll check(ll mid) {//每段和为mid
    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] == mid) {
            cnt++;
            now = 0;
        } else if (now + num[i] > mid) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    if (now > 0) cnt++;
    return cnt;
}

ll func() {
    ll l = x, r = mmax;//和最大的最小值，所以下界是每个数字自己一段，那么下界就是最大的内个数‘
    while (l != r) {//二分答案
        ll mid = (l + r) / 2;
        ll cnt = check(mid);//cnt代表分成几段
        if (cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax += num[i];//确定上下界
        x = max(x, num[i]);
    }
    cout << func() << endl;
    return 0;
}



/*#include<iostream>
using namespace std;
typedef long long ll;
ll n, m;
#define max_n 100000
ll a[max_n + 5];

ll is_val(ll x) {
    ll sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] > x) {
            sum = a[i];
            cnt++;
        }
        else sum += a[i];
    }
    return cnt <= m;
}    
int main() {
    ll maxx = 0;
    cin >> n >> m;
    ll l;
    ll r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = (a[i] > maxx ? a[i] : maxx);
        r += a[i];
    }
    l = maxx;
    ll res = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (is_val(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}*/
