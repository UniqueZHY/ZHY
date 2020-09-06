/*************************************************************************
	> File Name: ep36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时59分35秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
int is_val(int n, int base) {
    int x = n, tmp = 0;
    while (x) {
        tmp = tmp * base + x % base;
        x /= base;
    }
    return tmp == n;
}
int main() {
    int sum = 0;
    for (int i = 1; i <= max_n; i++) {
        if (is_val(i, 2) && is_val(i, 10)) sum += i; 
    }
    printf("%d\n", sum);
    return 0;
}
