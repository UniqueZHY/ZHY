/*************************************************************************
	> File Name: lg.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月12日 星期四 17时20分08秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int a;
    float b;
    scanf("%d", &a);
    if(a <= 150){
        b = a * 0.4463;
    }
    else if(a <=400){
        b = 150 * 0.4463 + (a - 150) * 0.4663;
    }
    else{
        b = 150 * 0.4463 + (400 - 150) * 0.4663 + (a - 401) * 0.5663;
    }
    printf("%.1f", b);
    return 0;
}