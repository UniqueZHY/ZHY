/*************************************************************************
	> File Name: 122_时间转换.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 17时24分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    int h, m, s, n;
    char t[10];
    scanf("%d", &n);
    s = n % 60;
    m = n / 60 % 60;
    h = n / 60 / 60;
   /* if(h > 12) {
        h = h - 12;
    }*/
    if(h < 12) {
        strcpy(t, "am");
    }
    if(h == 12 || h == 13){
        strcpy(t, "midnoon");
    }
    if(h >= 13 ){
        strcpy(t, "pm");
    }
    if(h > 12) h = h - 12;
    printf("%02d: %02d :%02d", h, m, s);
    printf("%s", t);
    return 0;
}
