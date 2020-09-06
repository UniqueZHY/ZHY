/*************************************************************************
	> File Name: 400_奇怪的象棋游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 00时20分53秒
 ************************************************************************/

#include<iostream>
#include<queue>
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
int check1[505][505], check2[505][505];
int x1, y1, x2, y2;
int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    q.push({x1, y1, 0});
    check1[x1][y1] = 1;
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        if (temp.x == 1 && temp.y == 1) {
            cout << temp.s << endl;
            break;
        }
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x <= 0 || y <= 0 || x >= x1 || y >= y1) continue;
            if (check1[x][y] == 0) {
                q.push({x, y, temp.s + 1});
                check1[x][y] = 1;
            }
        }
    }
    while (!q.empty()) q.pop();
    q.push({x2, y2, 0});
    check2[x2][y2] = 1;
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        if (temp.x == 1 && temp.y == 1) {
            cout << temp.s << endl;
            break;
        }
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x <= 0 || y <= 0 || x >= x2 || y >= y2) continue;
            if (check2[x][y] == 0) {
                q.push({x, y, temp.s + 1});
                check2[x][y] = 1;
            }
        }
    }

    return 0;
}
