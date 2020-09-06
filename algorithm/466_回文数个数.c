/*************************************************************************
	> File Name: 466_回文数个数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 12时30分17秒
 ************************************************************************/

#include<stdio.h>
int f(int n){
    int sum = 0;
    int x = n;
    while(x){
        sum = sum * 10 + x % 10;
        x  = x / 10;
    }
    if(sum == n) return 1;
    else return 0;
}
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++){
        if(f(j) == 1){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
