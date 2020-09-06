/*************************************************************************
	> File Name: 134.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 15时19分26秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int x, y, flag = 0;
	int a[1000];
    scanf("%d %d", &x, &y);
    for(int i = x; i <= y; i++){
		if(i % 11 == 0) {
            if (flag == 1) printf(" ");
            printf("%d", i);
            flag = 1;
        }
    }    		
    return 0;
}
