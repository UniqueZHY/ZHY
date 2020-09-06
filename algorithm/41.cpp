/*************************************************************************
	> File Name: 41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 14时46分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int f[1005][15][15];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i  = 0; i < k; i++) {
        for (int j = 0; j < k; j ++) {
            f[1][i][j] = (i == j);
        //当只有一块墙壁时，头尾墙壁只能一样才是一种方案
        }
    }
    //不成环的所有方案
    for (int t = 2; t <= n; t++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < k; l++) {
                    if (l - j) f[t][i][j] += f[t - 1][i][l];
                    //当l不等于j时,累加得到n个不成环墙壁的方法总数
                }
            }
        }
    }
    int ans = 0;
    //在所有方案中选出第一块和最后一块颜色不一样的方案
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i - j) ans += f[n][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
