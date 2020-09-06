/*************************************************************************
	> File Name: 145.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 16时02分14秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char s[21];
    char ans[21];
    int n, max_len = 0;
    scanf("%d", &n);
    for(int i = 0;i < n; i++){
        scanf("%s", s);
        int len = strlen(s);
        if(len > max_len) {
            strncpy(ans, s, sizeof(ans));
            max_len = len;
        }
    }

    printf("%s\n", ans);
    return 0;
}
