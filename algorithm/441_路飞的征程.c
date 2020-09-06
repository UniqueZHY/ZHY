/*************************************************************************
	> File Name: 441_路飞的征程.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 22时43分50秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int d, n, ans = 0;
    scanf("%d %d", &d, &n);
    for(int i = 0; i < n; i++){
        if((d + i) % 7 % 6 != 0 || (d + i) % 7 % 6 != 0){
            ans++;
        }
    }
    printf("%d", 2 * ans);
    return 0;
}
