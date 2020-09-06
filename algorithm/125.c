/*************************************************************************
	> File Name: 125.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 18时58分07秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
int main() {
    int h1, m1, s1, h, m, s, n;
    float b;
    char t[10];
    scanf("%d %d %d %d", &h, &m, &s, &n);
    s1 = s + n % 60;
    m1 = m + n / 60 % 60;
    h1 = h + n / 60 / 60; 
    if(h1 < 12){
        strcpy(t, "am");
    }
    if(s1 > 59){
        m1++;
        s1 -= 60;
    }
    if(m1 > 59){
        h1++;
        m1 -= 60;
    }
      if(h1 >= 24){
        h1 = h1 - 24; 
        strcpy(t, "am");
    }
    if(h1 > 12 && h1 < 24){
        h1 = h1 - 12;
        strcpy(t, "pm");
    
    }
    if(h1 == 12){
        strcpy(t, "pm");
    }
    if(n == 86400){
        h1 = 12;
        strcpy(t, "am");
    }
    b = (float)n / 86400 * 100;
    printf("%d:%d:%d", h1, m1, s1);
    printf("%s\n", t);
    printf("%.2f", b);
    printf("%%");
}
