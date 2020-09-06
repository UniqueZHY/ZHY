/*************************************************************************
	> File Name: 80_深搜.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 20时50分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

char mmap[505][505];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};//方向数组

int func(int x, int y) {
    for (int i = 0; i < 4; i++) {//四个方向
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == 'g') {
            return 1;
        }
        if (mmap[tx][ty] == '.') {
    //如果可以走，就把他标记为*证明走过了,以免重复而导致死循环
            mmap[tx][ty] = '*';
            if (func(tx, ty)) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy;
//从(1，1)点开始存，因为在第一行的时候如果向上走就会出现负数，用1来预防数组越界
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                //用sx,sy记录起点坐标
                sx = i;
                sy = j;
            }
        }
    }
    if (func(sx, sy)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
