/*************************************************************************
	> File Name: 174_批量替换字符串.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 18时40分18秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    char str[10000000];
    scanf("%[^\n]s", str);
    char s[5] = {"%20"};
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            strcpy(&str[i], &s[5]);
        }
    }
    printf("%s", str);
    return 0;
}
