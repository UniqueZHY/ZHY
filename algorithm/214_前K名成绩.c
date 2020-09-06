/*************************************************************************
	> File Name: 214_前K名成绩.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 00时40分39秒
 ************************************************************************/

#include<stdio.h>
int a[35];
void sort(int l){
    int v;
    for(int i = 0; i < l - 1; i++){
        for(int j = i + 1; j < l; j++){
            if (a[i] < a[j]){
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
    }
}
int main(){
    int n, p;
    float sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &p);
    sort(n);
    for(int j = 0; j < p; j++){
        sum += a[j];
    }
    printf("%.2f", sum / p);
    return 0;
}
