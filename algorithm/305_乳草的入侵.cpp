/*************************************************************************
	> File Name: 305_乳草的入侵.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 19时06分13秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
int n, m, x, y;
char mmap[105][105];

struct node {
    int x, y, step; 
};
int dir[8][2] = {
    1, 0, 0, 1, -1, 0, 0, -1,
    1, 1, 1, -1, -1, 1, -1, -1
};
int main() {
    cin >> m >> n >> y >> x;
    for (int i = 1; i <= n ; i++) {
        cin >> &mmap[i][1];
    }
    queue <node> que;
    que.push({n - x + 1, y, 0});
    mmap[n - x + 1][y] = '*';
    int ans;
    while (!que.empty()) {
        node t = que.front();
        que.pop();
        ans = t.step;
        for (int i = 0; i < 8; i++) {
            int x = t.x + dir[i][0];
            int y = t.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '*';
                que.push({x, y, t.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
