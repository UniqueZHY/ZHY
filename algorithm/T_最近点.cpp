/*************************************************************************
	> File Name: T_最近点对.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 19时21分40秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    double x, y;  
};

int n;
node p[100005];

double dis(int p1, int p2) {//求两点距离
    return sqrt((p[p1].x - p[p2].x) * (p[p1].x - p[p2].x) + (p[p1].y - p[p2].y) * (p[p1].y - p[p2].y) ) ;
}

double func(int l, int r) {
    if (l == r) return 210000000000;//若只有一个点，随便设一个最大值
    if (l + 1 == r) {//若是两个点，那最小距离就是两个点的距离
        return dis(l, r);
    }
    int mid = (l + r) / 2;
    double d = min(func(l, mid), func(mid + 1, r));
    //l~mid 最小距离 和 mid+1~r最小距离，d为两部分中中小的那个，
    for (int i = mid; i >= 0 && p[mid].x - p[i].x < d; i--) {//范围
        //求左边这一块距离中间小于d之内的点
        for (int j = mid + 1; j < r && p[j].x - p[mid].x < d; j++) {
            //求右边这一块距离中间小于d之间的点
            d = min(d, dis(i, j));
        }
    }
    return d;
}

bool cmp(node a, node b) {
    if (a.x == b.x) return a. y > b.y;
    return a.x > b.x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmp);
    double ans = func(0, n - 1);
    printf("%lf\n", ans);
    return 0;
}
