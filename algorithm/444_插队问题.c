/*************************************************************************
	> File Name: 444_插队问题.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 23时08分22秒
 ************************************************************************/

#include<stdio.h>
int a[105];
void swap(int m, int n){
    int t;
    t = a[m];
    a[m] = a[n];
    a[n] = t;
}
int main(){
    int n;
    int x, f = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for(int j = 0; j < n - x; j++){
        swap(n - 1, x - 1 + j);
    }
    for(int i = 0; i < n; i++){
        i != 0 && printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
