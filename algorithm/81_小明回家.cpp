/*************************************************************************
	> File Name: 81_小明回家.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 19时21分48秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y, s, f;
};
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, m, check[2005][2005];
char mmap[2005][2005];
int main() {
queue <node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push({i, j, 0, 0});
                check[i][j] = 1;//起点可能不止走一遍，所以也需要去重
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //没手机情况下这个点走过了
            if (temp.f == 0 && check[x][y] & 1) continue;//无手机不能走1，3 1&1和3&1都等于1,而2&1=0
            //有手机情况下这个点走过了，
            if (temp.f == 1 && check[x][y] & 2) continue;//有手机不能走2，3 1&2 和3&2都等于2 而1&2=0
            if (temp.f == 1 && mmap[x][y] == 'T') {//买到手机到家了
                cout << temp.s + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' ||mmap[x][y] == 'T') {
                que.push({x, y, temp.s + 1, temp.f});
                //就相当于有手机temp.f等于1，走过这个点那么这个点就是2，有手机走过
                //没手机temp.f等于0，走过这个点那么这个点就是1，没手机走过
                check[x][y] += temp.f + 1;
            }
            //到手机店，temp.f置为1,表示有手机了
            if (mmap[x][y] == 'P') {
                que.push({x, y, temp.s + 1, 1});
                check[x][y] = 3;
            }
        }
    }
    return 0;
}
