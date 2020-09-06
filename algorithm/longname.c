/*************************************************************************
	> File Name: longname.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月02日 星期六 16时32分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_n 100

char name[max_n + 5];
char ans[max_n + 5];
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        getchar();
        int max_len = 0;
        memset(name, 0, sizeof(name));
        memset(ans, 0, sizeof(name));
        for (int i = 0; i < n; i++) {
            scanf("%[^\n]s", name);
            getchar();
            int len = strlen(name);
            if (len > max_len) {
                strncpy(ans, name, sizeof(ans)); 
                max_len = len;
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}
