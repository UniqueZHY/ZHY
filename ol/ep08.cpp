/*************************************************************************
	> File Name: ep08.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 18时24分19秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define max_n 1000
char num[max_n + 5];
int main() {
    long long len = 0;
    while(~scanf("%s", num + len))
    len += strlen(num + len);
    long long p = 1, ans = 0, zero = 0;
    for (long long i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) p *= num[i];
        else zero += 1;
        if (i < 13) continue;
        if (num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if (zero == 0 && ans < p) ans = p;
    }
    printf("%lld\n", ans);
    return 0;
}




/*#include<stdio.h> 
#include<string.h>

#define max_n 1000

char num[max_n + 5];

int main(){
    int len = 0;
    while(~scanf("%s", num + len)) len += strlen(num + len);
    long long ans = 0, p = 1, zero = 0;
    for(int i = 0; num[i]; i++) {
        num[i] -= '0';//转换成整型
        if (num[i]) p *= num[i];
        else zero += 1;
        if (i < 13) continue;
        if (num[i - 13]) p /= num[i - 13];
        else zero -= 1;
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%ld\n", ans);
    return 0;
}*/
