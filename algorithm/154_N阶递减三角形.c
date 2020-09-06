/*************************************************************************
	> File Name: 154_N阶递减三角形.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 20时12分03秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = n - i; j > 0; j--){
            j != n - i && printf(" ");
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
