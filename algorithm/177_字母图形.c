/*************************************************************************
	> File Name: 177_字母图形.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 23时17分24秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char fun(char *a) {
    for(int i = strlen(a) - 2; i >= 0 ; i--){
        printf("%s", a[i]);
    }
    for(int j = 0; j < strlen(a) - 2; j++){
        printf("%s", a[j]);
    }
    return *a;
}
int main(){
    char s[30];
    scanf("%s", s);
    int len = strlen(s);
    /*for(int i = 0; i < len - 1; i++){
        fun(s);
        printf("%s\n", s);
    }*/
    fun(s);
    return 0;
}
