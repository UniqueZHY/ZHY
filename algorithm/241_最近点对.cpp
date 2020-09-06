/*************************************************************************
	> File Name: T_最近点对.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 19时21分40秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
struct node {
    double x, y, z;//xy代表坐标z代表所属集合
};
node p[200005];

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

double dis(int p1, int p2) {//距离
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) + (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y));
}

double func(int l, int r) {
    if (l == r) {//一个点，设为最大值
        return 2100000000;
    }
    if (l + 1 == r) {//两个点时,需判断是否在一个集合
        if (p[l].z != p[r].z) return dis(l, r);
        return 2100000000;
    }
    int mid = (l + r) / 2;
    double d = min(func(l, mid), func(mid + 1, r));
    for (int i = mid; i >= l && p[mid].x - p[i].x < d; i--) {
		 //求左边这一块距离中间小于d之内的点
        for (int j = mid + 1; j <= r && p[j].x - p[mid].x < d; j++) {
			            //求右边这一块距离中间小于d之间的点
            if (p[i].z != p[j].z) d = min(d, dis(i, j));
        }
    }
    return d;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {//规定集合1
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 1;
    }
    for (int i = 2 * n - 1; i >= n; i--) {//集合2
        scanf("%lf%lf", &p[i].x, &p[i].y);
        p[i].z = 2;
    }
    sort(p, p + 2 * n, cmp);
    double ans = func(0, 2 * n - 1);
    printf("%.3lf\n", ans);
    return 0;
}
