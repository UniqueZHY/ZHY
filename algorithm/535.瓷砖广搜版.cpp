/*************************************************************************
	> File Name: 535.瓷砖广搜版.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 10时09分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int h, w, ans = 1;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct node {
    int x, y;
};
queue <node> q;
int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') q.push({i, j});
        }
    }
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '#';
                ans++;
                q.push({x, y});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
