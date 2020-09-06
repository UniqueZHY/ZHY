/*************************************************************************
	> File Name: 213_分数字段统计.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 23时58分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int a[35];
void sort(int l){
    int v;
    for(int i = 0; i < l - 1; i++){
        for(int j = i + 1; j < l; j++){
            if (a[i] > a[j]){
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
    }
}
int main(){
    int n, b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        if( a[i] == 100) b1++;
        if(a[i] >= 90 && a[i] <= 99) b2++;
        if(a[i] >= 80 && a[i] <= 90) b3++;
        if(a[i] >= 70 && a[i] <= 79) b4++;
        if(a[i] >= 60 && a[i] <= 69) b5++;
        if(a[i] < 60) b6++;
    }
    sort(n);
    for(int j = n - 1; j >= 0; j--){
        printf("%d\n", a[j]);
    }
    printf("%d %d %d %d %d %d", b1, b2, b3, b4, b5, b6);
    return 0;
}
