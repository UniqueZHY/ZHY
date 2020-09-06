/*************************************************************************
	> File Name: 54_炒鸡大整数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 18时04分34秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define max_n 1000
int ans[max_n + 5];
int res[max_n + 5];

void solve(int x) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1,ans[1] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }

    }
    memset(res, 0, sizeof(res));
    res[0] = 1, res[1] = 1;
    for (int i = 1; i <= ans[0]; i++) {
        if (!ans[i]) continue;
        for (int j = 1; j <= res[0]; j++) {
            res[j] *= ans[i];
        }
        for (int k = 1; k <= res[0]; k++) {
            if(res[k] < 10) continue;
            res[k + 1] += res[k] / 10;
            res[k] %= 10;
            res[0] += (res[0] == k);
        }
    } 
    for (int i = res[0]; i >= 1; i--) {
        printf("%d", res[i]);
    }
    printf("\n");
}
int main() {
    int x;
    while (scanf("%d", &x) != EOF)
        solve(x);
    return 0;  
}
