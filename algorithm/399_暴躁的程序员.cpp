/*************************************************************************
	> File Name: 399_暴躁的程序员.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月29日 星期三 17时05分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 100005
int m, n;
int a[max_n];

int is_val (int x) {
    int last = 0;
    for (int i = 1; i < n; i++) {
        int cur = last + 1;
        while (cur < m && a[cur] - a[last] < x) {
            cur++;
        }
        if (cur == m) return 0;
        last = cur;
    }
    return 1;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    int l = 0, r = a[m - 1];
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (is_val(mid)) l = mid;
        else r = mid;
    }  
    cout << l << endl;
    return 0;
}
