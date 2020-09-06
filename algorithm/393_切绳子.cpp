/*************************************************************************
	> File Name: 393_切绳子.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月27日 星期一 18时36分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
double num[10005], mmax;

int check(double mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += num[i] / mid;
    }
    return cnt;
}

double func() {
    double l = 0, r = mmax;
    while (r - l > 0.00001) {
        double mid = (l + r) / 2;
        int x = check(mid);
        if (x >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n ;i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    double ans = func();
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
#define max_n 10005
int n, k;
int inf = 200005.0;
double a[max_n];

bool judge(double x) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += (int)(a[i] / x);
    }
    return num >= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double l = 0, r = inf;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (judge(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(2) << floor(l * 100) / 100 << endl;
    return 0;
}*/
