/*************************************************************************
	> File Name: ep07-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 18时43分48秒
 ************************************************************************/

#include<stdio.h> 
int is_val(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main() {
    int i, cnt;
    for (i = 2, cnt = 0; cnt < 10001; i++) {
        if (is_val(i)) cnt += 1;
    }
    printf("%d\n", i - 1);
    return 0;
}
