/*************************************************************************
	> File Name: EP1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 14时52分59秒
 ************************************************************************/

#include<stdio.h> 
int is_val(int n) {
    if (n % 3 == 0 || n % 5 == 0) return 1;
    return 0;
}
int main() {
    int sum = 0;
    for(int i = 0; i < 1000; i++) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
