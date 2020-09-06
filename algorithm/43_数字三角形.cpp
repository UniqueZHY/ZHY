/*************************************************************************
	> File Name: 43_数字三角形.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 18时07分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define max_n 1000
using namespace std;
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    cout << dfs(0, 0, n) << endl;
    return 0;
}



/*int val[max_n + 5][max_n + 5]= {0};
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = max_n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}*/
