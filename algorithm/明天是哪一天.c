/*************************************************************************
	> File Name: text.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月01日 星期五 20时59分23秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int x;
    int y, m, d, y1, m1, d1;
    int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d", &x);
    scanf("%d %d %d", &y, &m, &d);
    m1 = m;
    y1 = y;
    d1 = d;
    d1 = d + x;
    
    while(d1 > mon[m1]){
        if(y1 % 4 == 0 & y1 % 100 != 0 || y1 % 400 == 0){
        mon[2] = 29;
        }
        else{
            mon[2] = 28;
        }
        d1 = d1 - mon[m1];
        m1++;
        if(m1 > 12){
            y1++;
            m1 = 1;
        }
    }
    
    printf("%d %d %d", y1, m1, d1);
 return 0;
}
