/*************************************************************************
	> File Name: 147.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 19时06分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    char s[10005];
    char a;
    scanf("%s", s);
    a = s[strlen(s) - 1];
    if(a % 2 == 0)
    printf("YES\n");
    else 
    printf("NO\n");

}
