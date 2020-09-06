/*************************************************************************
	> File Name: 529_龙与虫.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 20时40分14秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, check[150][150];
char mmap[150][150];
int dir[8][2] = {
    0, 1, 1, 0, 0, -1, -1, 0,
    1, -1, 1, 1, -1, -1, -1, 1
};
int func() {
    int a, b, c, d;
    cin >> c >> d >> a >> b;
    if (!a) return 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 8; i++) {//找终点，也就是能杀死敌人的点
        for (int j = 1; 1; j++) {
            int x = c + j * dir[i][0];
            int y = d + j * dir[i][1];
            if (mmap[x][y] != 'O') break;//到头了或者走不了了
            check[x][y] = 2;//将终点标记为2
        }
    }
    check[c][d] = 2;//敌人所在的点也标记为2
    if (check[a][b] == 2) {//虫子和敌人在一个位置
        cout << 0 << endl;
        return 1;
    }
    queue <node> que;
    que.push({a, b, 0});
    check[a][b] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (check[x][y] == 2) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            //能走并且没走过
            if (mmap[x][y] == 'O' && check[x][y] != 1) {
                check[x][y] = 1;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << "Impossible!" << endl;
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    while (func()) {  }//多组数据
    return 0;
}
