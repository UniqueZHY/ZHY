/*************************************************************************
	> File Name: 186_弹簧板.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 13时24分12秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int a[100005];
    int n, t = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
	int dis = 0;
    while(dis < n){
        dis += a[dis];
        t++;
    }
    printf("%d", t);
    return 0;
}
