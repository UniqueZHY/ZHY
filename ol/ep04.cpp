/*************************************************************************
	> File Name: ep04-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 18时07分44秒
 ************************************************************************/

#include<stdio.h>

int is_val(int n, int base) {//判断一个数字在base进制下是否为回文数
    int x = n, tmp = 0;
    while (x) {
        tmp = tmp * base + x % base;
        x /= base;
    }
    return tmp == n;
}
int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for(int j = i; j < 1000; j++) {
            if (is_val(i * j, 10) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
