/*************************************************************************
	> File Name: 回文数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 16时27分01秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int n, x, sum = 0;
    scanf("%d", &n);
    x = n;
    while(x){
        sum = 10 * sum + x % 10;
        x /= 10;
    }
    if(sum == n) printf("YES");
    else printf("NO");
    return 0;
}
