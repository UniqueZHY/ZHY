/*************************************************************************
	> File Name: 140.输出字母菱形.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 16时25分55秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int n;
    int c = 'A'; 
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++){
        for(int j = n - i; j > 0; j--){
            printf(" ");
        }
        for(int j = 0; j < (2 * i) - 1; j++){
            printf("%c", c);
        }
        printf("\n");
        c++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < (n - i) * 2  - 1; j++){
            printf("%c", c);
        }
        printf("\n");
        c--;
    }
    return 0;
}

