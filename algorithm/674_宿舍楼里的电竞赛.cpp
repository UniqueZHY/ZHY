/*************************************************************************
	> File Name: 674_宿舍楼里的电竞赛.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月29日 星期三 19时25分46秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//排名排在当前队伍前的队伍数x 排名排在当前队伍后的队伍数y 
//如果x + y = n - 1 就说明当前队伍排名是确定的

int n, m, ans[105][105], x[105], y[105];//从a到b的最短距离
int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ans[a][b] = 1;
    }
    //弗洛伊德
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
                //当前值和中转值取较小的
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] != 0x3f3f3f3f) {
                x[j]++;
                y[i]++;
            }
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] + y[i] == n - 1) {
            //之前之后的排名都确定了
            fin++;
        }
    }
    cout << fin << endl;
    return 0;
}
