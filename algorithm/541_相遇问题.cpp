/*************************************************************************
	> File Name: 541_相遇问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 19时05分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n, m, atime[2][20][20], ans[2][100000], ans_num[2];
//ppl 哪个人 loc从哪开始走 cose花费多长时间
void func (int ppl, int loc, int cost) {
    if (loc == n) {
        ans[ppl][ans_num[ppl]] = cost;
        //记录方法总数
        ans_num[ppl]++;
        return ;
    }
    //从1 到2 到3 一直按顺序往下所需要花费的时间
    for (int i = loc + 1; i <= n; i++) {
        if (atime[ppl][loc][i]) {
            func(ppl, i, cost + atime[ppl][loc][i]);
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 0; i  <m ; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //表示从a到b和b从到a的时间是一样的
        atime[0][a][b] = atime[0][b][a] = c;
        atime[1][a][b] = atime[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + ans_num[0]);
    sort(ans[1], ans[1] + ans_num[1]);
    for (int i = 0; i < ans_num[0]; i++) {
        for (int j = 0; j < ans_num[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
