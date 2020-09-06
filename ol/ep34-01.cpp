/*************************************************************************
	> File Name: ep34-01.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时44分47秒
 ************************************************************************/
#include<stdio.h>
#define max_n 2903040

//记忆化搜索
int keep[10] = {0};
int fac(int n) {
    if (keep[n]) return keep[n];
    if (n == 0) return 1;
    if (n == 1) return 1;
    return keep[n] = n * fac(n - 1);
}
int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += fac(x % 10);
        x /= 10;
    }
    return tmp == n;
}

int main() {
    int sum = 0;
    for(int i = 3; i <= max_n; i++) {
        if (is_val(i)) sum += i; 
    }
    printf("%d\n", sum);
    return 0;
}



/*#include<stdio.h>
#define max_n 2903040
//原始
int fac(int n) {
    if(n == 0) return 1;
    if (n == 1) return 1;
    return n * fac(n - 1);
}

int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += fac(x % 10);
        x /= 10;
    }
    return tmp == n;
}

int main() {
    int sum = 0;
    for(int i = 3; i <= max_n; i++) {
        if (is_val(i)) sum += i; 
    }
    printf("%d\n", sum);
    return 0;
}*/
