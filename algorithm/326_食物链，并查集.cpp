/*************************************************************************
	> File Name: 326_食物链，并查集.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月24日 星期五 14时23分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 50000
// 0 a b ab同类 
// 1 a b a吃b
// 2 a b a被吃b
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
    val[x] %= 3;//权值等于自己到根节点权值相加的和
    return fa[x] = root;
}

int merge(int x, int y, int t) {
    int a = get(x), b = get(y);
    if (a == b) {
        //判断x y关系是否等于t
        return (val[x] - val[y] - t) % 3 == 0;//(1)
    }
    fa[a] = b;//将ab连接起来
    val[a] = (t + val[y] - val[x] + 3) % 3;//(2)
    return 1;
}

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    init(n);
    for (int i = 0; i < k; i++) {
        int x, y, t;
        cin >> t >> x >> y;
        t -= 1;
        /*ab同类
         * if (t == 1) t = 0;
         * a吃b
         * if (t == 2) t = 1
        * */
        if (x <= n && y <= n && merge(x, y, t)) continue;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
