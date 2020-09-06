/*************************************************************************
	> File Name: 468_最大公约数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 10时31分14秒
 ************************************************************************/

#include<stdio.h>
int gcd(int x, int y){
    int r = x % y;
    while(r){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));

    return 0;
}
