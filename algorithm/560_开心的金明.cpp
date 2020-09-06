/*************************************************************************
	> File Name: 560_开心的金明.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时04分35秒
 ************************************************************************/
//欲求重要程度乘价格最大，就可把这点作为价值,总钱数相当于背包重量
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 30000
int value[MAX_N + 5], weight[MAX_N + 5], ans[MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j > 0; j--) {
            if (j < weight[i]) break;
            else ans[j] = max(ans[j], ans[j - weight[i]] + (value[i] * weight[i]));
        }
    }
    cout << ans[n] << endl;
    return 0;
}
