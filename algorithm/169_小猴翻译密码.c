/*************************************************************************
	> File Name: 169_小猴翻译密码.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 15时20分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char str[30];
    int c[30];
    char pw[35];
    int n;
    char s;
    int a, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", &str[i]);
        scanf("%d", &c[i]);
    } 
    scanf("%s", pw);
    
    for(int i = 0; i < strlen(str); i++){
        for(int j = 0; j < strlen(pw); j++){
            if(str[i] == pw[j]){
                sum += c[i];
            }
        }
    }
    printf("%d", sum);
    return 0;
}
