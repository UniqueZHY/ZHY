/*************************************************************************
	> File Name: 181_大小写翻转.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 19时45分21秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
            continue;
        } 
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    printf("%s", s);
    return 0;
}
