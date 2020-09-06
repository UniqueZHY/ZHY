/*************************************************************************
	> File Name: ep18-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 09时30分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 20
int val[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5] = {0};
int dfs(int i, int j, int n) {
    if (i + 1 == n) return val[i][j];
    if (keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n);
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = (val1 > val2 ? val1 : val2) + val[i][j];
}
int main() {
    for (int i = 0; i < max_n; i++) {//用input时用max_n, 正常./a.out 用15
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, max_n) << endl;
    return 0;
}
