/*************************************************************************
	> File Name: 33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 18时08分51秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int is_val(int x, int y) {
    int x1 = x / 10, x2 = x % 10;
    int y1 = y / 10, y2 = y % 10;
    if (!x2 || !y2) return 0;
    if (x1 == y1 && x2 * y == y2 * x) return 1;
    if (x1 == y2 && x2 * y == y1 * x) return 1;
    if (x2 == y1 && x1 * y == y2 * x) return 1;
    if (x2 == y2 && x1 * y == y1 * x) return 1;
    return 0;
}

int main() {
    int x = 1, y = 1, c = 1;
    for (int a = 10; a < 100; a++) {
        for (int b = a + 1; b < 100; b++) {
            if (!is_val(a, b)) continue;
            printf("%d %d\n", a, b);
            x *= a, y *= b;
            c = gcd(x, y);
            x /= c, y /= c;
        }
    }
    printf("%d\n", y);
    return 0;
}
