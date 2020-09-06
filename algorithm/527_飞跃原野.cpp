/*************************************************************************
	> File Name: 527_飞跃原野.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 20时00分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
    int x, y, s, d;
};
int n, m, d, check[105][105][105];//表示飞到当前这个点剩余能量
char mmap[105][105];


int main() {
    queue <node> que;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    que.push({1, 1, 0, d});
    for (int i = 0; i <= d; i++) {
        check[1][1][i] = 1;//起点的所有情况都标记一下，可能飞回来
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {//飞
            for (int j = 2; j <= temp.d; j++) {//最起码飞2，一个就走了
                int x = temp.x + j * dir[i][0];//在当前方向上飞j步
                int y = temp.y + j * dir[i][1];
                if (x == n && y == m) {
                    cout << temp.s + 1 << endl;
                    return 0;
                }
                if (mmap[x][y] == 0) break;//边界直接，break
                //点可走并且没走过
                if (mmap[x][y] == 'P' && check[x][y][temp.d - j] == 0) {
                    check[x][y][temp.d - j] = 1;
                    que.push({x, y, temp.s + 1, temp.d - j});
                }
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.s + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
                check[x][y][temp.d] = 1;
                que.push({x, y, temp.s + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
