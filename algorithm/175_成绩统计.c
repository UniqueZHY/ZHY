/*************************************************************************
	> File Name: 175_成绩统计.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 19时16分32秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n, c = 0, l = 0, z = 0, y = 0; 
    int g[30];
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d", &g[i]);
    }
    for(int j = 0; j < n; j++){
        if(g[j] < 60){
            c++;
        } else if(g[j] < 80){
            z++;
        } else if(g[j] < 90){
            l++;
        } else 
            y++;
    }
    printf("You %d\n", y);
    printf("Liang %d\n", l);
    printf("Zhong %d\n", z);
    printf("Cha %d\n", c);
    return 0;
}
