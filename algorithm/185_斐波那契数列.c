/*************************************************************************
	> File Name: 185_斐波那契数列.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 23时25分49秒
 ************************************************************************/

#include<stdio.h>
int fun(int n){
    if(n == 1 || n == 2) return 1;
    if(n > 2) return fun(n - 1) + fun(n - 2);
}
int main(){
    int n;
    scanf("%d", &n);
    int ans = fun(n);
    printf("%d", ans);
    return 0;
}
