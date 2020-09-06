/*************************************************************************
	> File Name: 327_关押罪犯.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 19时19分44秒
 ************************************************************************/
/*将所有怒气值排序，依次从上往下分配，看看是否为1(是否能分到不同监狱),直到第一个无法分到不同监狱的罪犯的怒气值即为所求
* */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000
int fa[MAX_N + 5], val[MAX_N + 5];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
    return ;
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x]%= 2;
    return fa[x] = root;
}

int merge(int a, int b, int t) {
    int x = get(a), y = get(b);
    if (x == y) {
        return (val[a] - val[b] - t) % 2 == 0;
    }
    fa[x] = y;
    val[x] = (t + val[b] - val[a] + 2) % 2;
    return 1;
}

struct Data {
    int x, y, c;
} arr[MAX_M + 5];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    arr[m].x = arr[m].y = 1;//如果所有罪犯都能放在不同监狱中，应输出0，而当前arr[m].x和arr[i].y是不可能为0的所以会输出0(小技巧)
    arr[m].c = 0;
    for (int i = 0; i <= m; i++) {
        if (merge(arr[i].x, arr[i].y, 1)) continue;
        //如果可以将当前两个犯人放在两个监狱就continune
        cout << arr[i].c << endl;//说明不能放在两个监狱里
        break;
    }
    //cout << 0 << endl;
    return 0;
}
