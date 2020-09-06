/*************************************************************************
	> File Name: 139_输出A字菱形.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 14时33分21秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = n - i; j > 0; j--){
            printf(" ");
        }
        for(int j = 0; j < 2 * i; j++){
            printf("A");
        }
        printf("\n");
    }
    for(int i = 1 ; i <= n - 1; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < (n - i) * 2 ; j++){
            printf("A");
        }
        printf("\n");
    }
    return 0;
}
