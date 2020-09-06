/*************************************************************************
	> File Name: em02-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 15时52分01秒
 ************************************************************************/

#include<stdio.h>
#define N 4000000
int main() {
    int a = 0, b = 1, c;
    int sum = 0, n = 0;
    while (a + b <= N) {
        n += 1;
        /*c = a + b;
        a = b;
        b = c;*/
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        sum += b;
    }
    printf("n = %d, %d\n", n, sum);
    return 0;
}
