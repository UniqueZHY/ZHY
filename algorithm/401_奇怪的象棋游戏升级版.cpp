/*************************************************************************
	> File Name: 401_奇怪的象棋游戏升级版.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 21时36分06秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node {
    int x, y, s;
};
queue <node> q;
int dir[12][2] = {
    1, 2, 1, -2, -1, 2, -1, -2, 
    2, 1, 2, -1, -2, 1, -2, -1,
    2, 2, 2, -2, -2, 2, -2, -2
};
int mmap[505][505];
//int ans[505][505];
int n, a, b;
int main() {
    //mmap[1][1] = 1;
    q.push({1, 1, 0});
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        for (int i = 0; i < 12; i++) {
            int x = t.x + dir[i][0];
            int y = t.y + dir[i][1];
            if (x < 1 || y < 1 || x > 500 || y > 500 || mmap[x][y]) continue;
            mmap[x][y] = t.s + 1;
            q.push({x, y, t.s + 1});
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << mmap[a][b] << endl;
    }
    return 0;
}

/*int main() {
    cin >> n;
    while (n--) {
        while(!q.empty()) q.pop();
        memset(mmap, 0, sizeof(mmap));
        cin >> a >> b;
        mmap[1][1] = 1;
        q.push({1, 1, 0});
        while(!q.empty()) {
            if (ans[a][b]) {
                cout << ans[a][b] << endl;
                break;
            }
            node t = q.front();
            q.pop();
            if (t.x == a && t.y == b) {
                cout << t.s << endl;
            }
            for (int i = 0; i < 12; i++) {
                int x = t.x + dir[i][0];
                int y = t.y + dir[i][1];
                if (x < 1 || y < 1 || x > a || y > b) continue;
                if (!mmap[x][y]) {
                    mmap[x][y] = 1;
                    ans[x][y] = t.s + 1;
                    q.push({x, y, t.s + 1});
                }
            }
        }
    }
    return 0;
}*/
