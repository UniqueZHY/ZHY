/*************************************************************************
	> File Name: 172_排序名单.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 16时52分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void pop(char str[110][110]){
    char t[110];
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < 10 - i; j++){
            //if(str[j] > str[j + 1]){
            if(strcmp(str[j], str[j + 1]) > 0){
                strcpy(t, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], t);
            }
        }
    }
}
int main() {
    char s[110][110];
    for(int i = 0 ; i < 10 ; i++){
        scanf("%s", s[i]);
    }
    pop(s);
    for(int j = 0; j < 10; j++){
        printf("%s\n", s[j]);
    }
    return 0;
}
