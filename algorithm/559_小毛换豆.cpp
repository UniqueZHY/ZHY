/*************************************************************************
	> File Name: 559_小毛换豆.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 18时26分49秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct Treat {
    double s;
    double f;
    double val;
}Treat;

bool cmp(Treat x, Treat y) {
    return x.val > y.val;
}

int main() {
    int m, n;
    double get = 0;
    cin >> m >> n;
    Treat a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
        a[i].val = a[i].s / a[i].f;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        get += m > a[i].f ? a[i].s : (m * a[i].val);
        m -= m > a[i].f ? a[i].f : m;
        if (m == 0) break;
    }   
    printf("%.3f", get);
    return 0;
}
