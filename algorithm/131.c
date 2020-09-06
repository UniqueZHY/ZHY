/*************************************************************************
	> File Name: 131.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 22时41分25秒
 ************************************************************************/

#include<stdio.h>
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int n;
    int max, min;
    int a[10000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    min = a[0];
    for(int i = 0 ; i < n; i++){
        if(a[i] < min)
        swap(&a[i], &min);
    }
    max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max)
        swap(&a[i], &max);
    }
    if(min > max){
        swap(&min, &max);
    }
    printf("%d\n", max - min);
    return 0;
}
