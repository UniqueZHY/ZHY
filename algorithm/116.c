/*************************************************************************
	> File Name: 116.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 16时01分43秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main(){
    int a[3];
    int t;
    for(int i = 0;i < 3; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < 3; i++){
        for(int j = 0; j < 3 - i; j++){
            if(a[j] > a[j + 1]){
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    if(a[0] + a[1] > a[2]){
        if(pow(a[0], 2) + pow(a[1], 2) > pow(a[2], 2))
        printf("acute triangle\n");
        if(pow(a[0], 2) + pow(a[1], 2) == pow(a[2], 2))
        printf("right triangle\n");
        if(pow(a[0], 2) + pow(a[1], 2) < pow(a[2], 2))
        printf("obtuse triangle\n");
    }
    else
    printf("illegal triangle\n");
    return 0;
}
