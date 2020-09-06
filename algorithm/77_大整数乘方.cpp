/*************************************************************************
	> File Name: 77_大整数乘方.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月23日 星期一 23时43分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max_n 150
long long ans[max_n + 5] = {0};
using namespace std;
int main() {
    int m;
    int n;
    cin >> m;
    cin >> n;
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= m; 
        }  
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
