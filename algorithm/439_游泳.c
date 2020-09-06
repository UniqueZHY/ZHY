/*************************************************************************
	> File Name: 439_游泳.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 00时24分50秒
 ************************************************************************/

#include<stdio.h>
int main() {
    double x, y = 2, sum = 0;
    int n = 0;
    scanf("%lf", &x);
    while(sum < x){
        sum += y;
        y *= 0.98;
        n++;
    }
    printf("%d", n);
    return 0;
}

