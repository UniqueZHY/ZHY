/*************************************************************************
	> File Name: 398_马的遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 18时48分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
    int x, y, step;
};
queue <node> que;
int dir[8][2] = {
    1, 2, 1, -2, 2, 1, 2, -1,
    -1, 2, -1, -2, -2, 1, -2, -1
};
int n, m, x, y;
int mmap[405][405];
int main() {
    cin >> n >> m >> x >> y;
    mmap[x][y] = -1;
    que.push({x, y, 0});
    while (!que.empty()) {
        node t = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = t.x + dir[i][0];
            int y = t.y + dir[i][1];
            if (x < 1 || y < 1|| x > n || y > m || mmap[x][y]) continue;
            mmap[x][y] = t.step + 1;
            que.push({x, y, mmap[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            (j != 1) && cout << " ";
            if (mmap[i][j] == 0) cout << -1;
            else if (mmap[i][j] == -1) cout << 0;
            else cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
