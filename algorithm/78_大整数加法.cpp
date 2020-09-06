/*************************************************************************
	> File Name: 78_大整数加法.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月23日 星期一 17时14分15秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define max_n 52
char str1[max_n + 5] = {0};
char str2[max_n + 5] = {0};
int ans[max_n + 5] = {0};
int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    int len = strlen(str1);
    if (ans[0] < len) ans[0] = len;
    for (int i = 0; i < len; i++) {
        ans[len - i] += str1[i] + str2[i] - '0' - '0';
    }
    for (int k = 1; k <= len; k++) {
        if (ans[k] < 10) continue;
        ans[k + 1] += ans[k] / 10;
        ans[k] %= 10;
        ans[0] += (k == ans[0]);
    }
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
