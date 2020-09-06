/*************************************************************************
	> File Name: lx大整数幂次.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 16时38分37秒
 ************************************************************************/

#include<stdio.h>
#define max_n 500

void solve(int a, int b) {
    int ans[max_n + 5] = {0};
    ans[0] = 1, ans[1] = 1;
    for (int i = 0; i <= b; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= a;
        }
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
}    
int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b)) solve(a, b);
    return 0;
}
