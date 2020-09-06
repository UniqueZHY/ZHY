/*************************************************************************
	> File Name: 120.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 08时39分07秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    if(m > 12){
        printf("NO");
    }
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8|| m == 10 || m == 12){
             if(d <= 31 && d > 0) printf("YES");
             else printf("NO");
    }
    if(m == 4|| m == 6|| m == 9|| m == 11){
        if( d <= 30 && d > 0 ) printf("YES");
        else printf("NO");
    }
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        if(m == 2)
            if(d <= 29 && d > 0) printf("YES");
            else  printf("NO");
    }
    else{
        if(m == 2){
            if( d <= 28 && d > 0 ) printf("YES");
            else printf("NO");
        }
    }
    return 0;
}
