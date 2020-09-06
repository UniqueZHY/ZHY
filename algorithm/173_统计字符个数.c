/*************************************************************************
	> File Name: 173_统计字符个数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 18时09分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int d = 0, l = 0, o = 0, s = 0;
    scanf("%[^\n]",&str);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            d++;
        } 
        else if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
            l++;
        }
        else if(str[i] == ' '){
            s++;
        }
        else{
            o++;
        } 
    }
    printf("%d %d %d %d", l, d, s, o);
    return 0;
}
