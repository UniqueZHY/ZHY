/*************************************************************************
	> File Name: 184_路飞吃桃.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 23时00分02秒
 ************************************************************************/

/*#include<stdio.h>
int peach(int n){
    if(n == 1) return 1;
    return (peach(n - 1) + 1) * 2;

}
int main(){
    int n, ans;
    scanf("%d", &n);
    printf("%d", peach(n));
    return 0;
}*/
#include<stdio.h>
int peach(int k, int n) {
    if(k == n) return 1;
    return 2 * (peach(k + 1, n) + 1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", peach(1, n));
     return 0;
}
