/*************************************************************************
	> File Name: 118.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 17时08分41秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main(){
    int x, y;
    scanf("%d", &x);
    y = abs(1900 - x) % 12;
    if(x >= 1900){
        if(y == 0) printf("rat");
        if(y == 1) printf("ox");
        if(y == 2) printf("tiger");
        if(y == 3) printf("rabbit");
        if(y == 4) printf("dragon");
        if(y == 5) printf("snake");
        if(y == 6) printf("horse");
        if(y == 7) printf("sheep");
        if(y == 8) printf("monkey");
        if(y == 9) printf("rooster");
        if(y == 10) printf("dog");
        if(y == 11) printf("pig");
    }
    else{
        if(y == 1) printf("pig");
        if(y == 2) printf("dog");
        if(y == 3) printf("rooster");
        if(y == 4) printf("monkey");
        if(y == 5) printf("sheep");
        if(y == 6) printf("horse");
        if(y == 7) printf("snake");
        if(y == 8) printf("dragon");
        if(y == 9) printf("rabbit");
        if(y == 10) printf("tiger");
        if(y == 11) printf("ox");
        if(y == 12) printf("rat");
    }
    return 0;

}
