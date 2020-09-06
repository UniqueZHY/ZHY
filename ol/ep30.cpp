/*************************************************************************
	> File Name: ep30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 19时47分53秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 354284

int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += (int)pow(x % 10, 5);
        x /= 10;
    }
    return tmp == n;
}
int main() {
    int sum = 0;
    for (int i = 2; i <= max_n; i++){
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
