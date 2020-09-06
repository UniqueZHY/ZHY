/*************************************************************************
	> File Name: text所有数的最小素因子.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 19时55分55秒
 ************************************************************************/
#include<stdio.h>
#define max_n 10000
int prime[max_n + 5] = {0};
void init () {
    for(int i = 2; i <= max_n; i++) {
        if(prime[i]) continue;
        for(int j = i; j <= max_n; j += i) {
            if(prime[j]) continue;
            prime[j] = i;//用下一个素因子覆盖上一个
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", prime[n]);
    }
}

