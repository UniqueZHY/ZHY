/*
	> File Name: 152_三天后是星期几.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 13时41分45秒
 ************************************************************************/

#include<stdio.h>
int main() {
    char s[10][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int a;
    scanf("%d", &a);
    
    printf("%s", s[(a + 3) % 7]);
    return 0;
}
