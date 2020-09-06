/*************************************************************************
	> File Name: ex_ged.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 20时09分01秒
 ************************************************************************/

#include<stdio.h>
int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    //xx = *y;
    //yy = *x - a / b * xx;
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
} 
int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }

    return 0;
}
