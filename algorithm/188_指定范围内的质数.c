/*************************************************************************
	> File Name: 188_指定范围内的质数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 23时19分41秒
 ************************************************************************/










/*#include<stdio.h>
int prime(long int a){
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0) return 0;
    }
    return 1;
}
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    swap(&n, &m);
    //printf("%d %d ", n, m);
    for(int i = n; i <= m; i++){
        if(prime(i) == 1)
        printf("%d\n", i);
    }
}*/
