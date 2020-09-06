/*************************************************************************
	> File Name: 168_规范化名字.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 23时48分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void pop(char str[105][105], int n){
    char s[100];
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j;i++){
            if(strcmp(str[i], str[i + 1]) > 0){
                strcpy(s, str[i]);
                strcpy(str[i], str[i + 1]);
                strcpy(str[i + 1], s);
            }
        }    
    }
    for(int j = 0; j < n; j++){
        printf("%s\n", str[j]);
    }
}
int main(){
    char str[105][105];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
        for(int j = 0; str[i][j] != 0; j++){
            if(str[i][j] >= 'A' && str[i][j] <= 'Z'){
                str[i][j] += 32; 
            }
            if(str[i][0] >= 'a' && str[i][0] <= 'z')
                str[i][0] -= 32;
        }
    }
    pop(str, n);
    return 0;
}
