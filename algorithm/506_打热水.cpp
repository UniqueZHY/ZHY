/*************************************************************************
	> File Name: 506_打热水.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时07分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    int n;
    int t;
};
node a[1005];
bool cmp(node a, node b) {
    return a.t < b.t;
}
int main() {
    int n;
    double ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].t;
        a[i].n = i + 1;
    }
    sort(a, a + n, cmp);
    int now = 0;
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << a[i].n;
        ans += now;
        now += a[i].t;
    }
    cout << endl;
    printf("%.2f", ans / n);
    return 0;
}
