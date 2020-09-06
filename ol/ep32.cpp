/*************************************************************************
	> File Name: ep32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 16时51分05秒
 ************************************************************************/
#include<stdio.h>
#include<math.h>
#define max_n 10000
int keep[max_n + 5] = {0};
int add_to_num (int *num, int n) {
    while (n) {
    if (num[n % 10]) return 0;
    num[n % 10] += 1;
    n /= 10;
    }
    return 1;
}

int digit(int n) {
    int d = floor(log10(n)) + 1;
    return d;
}


int is_val(int a, int b) {
    if (digit(a) + digit(b) + digit(a * b) != 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_to_num(num, a);
    flag = flag && add_to_num(num, b);
    flag = flag && add_to_num(num, a * b);
    return flag;
}


int main() {
    int sum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if(!is_val(a, b)) continue;
            printf("%d * %d = %d\n", a, b, a * b);
            if (keep[a * b]) continue;
            keep[a * b] = 1;
            sum += a * b;
        }
    }
    printf("%d\n", sum);
}
