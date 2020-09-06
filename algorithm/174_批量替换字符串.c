/*************************************************************************
	> File Name: 174_批量替换字符串.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 18时40分18秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    char str[1000005];
    scanf("%[^\n]s", str);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            printf("%%20");
        }
        else  printf("%c", str[i]);
    }
    return 0;
}
