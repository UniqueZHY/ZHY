/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 20时35分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_n 10
int arr[max_n + 5][max_n + 5];
int dir[8][2] = {
    {-2, 1}, {-2, -1}, {2, -1},{2, 1}, 
    {-1, -2}, {-1, 2}, {1, -2}, {1,2}
};
int T, n, m, sx, sy;
int ans = 0;
void dfs(int x, int y, int cnt) {
    if (x < 0 || x >= n || y < 0 || y >= m) return ;
    if (arr[x][y]) return ;
    if (cnt >= n * m) {
        ans += 1;
        return ;
    }
    arr[x][y] = 1;
    for (int k = 0; k < 8; k++) {
        int dx = x + dir[k][0];
        int dy = y + dir[k][1];
        dfs(dx, dy, cnt + 1);
        //回溯过程，对完成后换另一个方向
    }
    arr[x][y] = 0;
}
int main() {
    scanf("%d", &T);
    while(T--){
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d%d", &n, &m, &sx, &sy); 
        int cnt = 1;
        dfs(sx, sy, cnt);
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}
