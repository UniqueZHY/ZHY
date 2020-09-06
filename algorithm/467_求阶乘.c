/*************************************************************************
	> File Name: 467_求阶乘.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 11时17分03秒
 ************************************************************************/

#include<stdio.h>
long long int func(long long x){
    if(x == 1){
        return 1;
    } else {
        return x * func(x - 1);
    } 
}
int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", func(n));
    return 0;
}
