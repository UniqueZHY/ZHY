/*************************************************************************
	> File Name: D_填涂颜色.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月18日 星期三 16时40分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
int map[35][35];
bool vis[35][35];
int n;

void dfs (int x, int y) {
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || map[x][y] == 1 || vis[x][y]) return ;
    map[x][y] = 3;
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1; i  <= n; i++) {
        for (int j = 1; j <= n; j++) {
            (j > 1) && cout << " ";
            if (map[i][j] == 0) cout << "2";
            else if (map[i][j] == 3) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
    return 0;
}
