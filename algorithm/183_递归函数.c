/*************************************************************************
	> File Name: 183_递归函数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 22时47分42秒
 ************************************************************************/

#include<stdio.h>
int fun(int x) {
    if(x <= 0) return 0;
    if(x == 1) return 1;
    if(x > 1 && x % 2 == 0) return 3 * fun(x / 2) - 1;
    if(x > 1 && x % 2 == 1) return 3 * fun((x + 1) / 2) - 1;
}
int main() {
    int a, ans;
    scanf("%d", &a);
    ans = fun(a);
    printf("%d", ans);
    return 0;
}
