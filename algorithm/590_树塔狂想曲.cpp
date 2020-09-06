/*************************************************************************
	> File Name: 590_树塔狂想曲.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 20时46分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, num[1005][1005], down[1005][1005], up[1005][1005], mmax[1005], mmax_ind[1005], mmax2[1005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        int ind1 = 0, max1 = 0, max2 = 0;
        //   坐标       最大值       次大值
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            //经过ij的最大的点
            if (t > max1) {
            //如果t大于max就更新max
                max1 = t;
                ind1 = j;
            }
        }
        for (int j = 1; j <= i; j++) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > max2 && j != ind1) {//次大值
                max2 = t;
            }
        }
        mmax[i] = max1;//第i行最大值
        mmax_ind[i] = ind1;//第i行最大值坐标
        mmax2[i] = max2;//第i行次大值
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
            continue;
        }
        if (mmax_ind[a] == b) {//如果第a行被Ban的点正好是该行最大值
            printf("%d\n", mmax2[a]);//输出次大值
        } else {
            printf("%d\n", mmax[a]);
        }
    }
    return 0;
}
