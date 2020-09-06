/*************************************************************************
	> File Name: ep25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 14时13分26秒
 ************************************************************************/


/*#include<stdio.h>
#include<math.h>
int f[3];

int main() {
    int n = 2;
    f[1] = 1, f[2] = 2;
    while (floor(log10(f[n % 3])) + 1 < 3) {
        n += 1;
        f[n % 3] = f[(n - 1) % 3] + f[(n - 2) % 3];
    }
    printf("%d\n", n);
    return 0;
}*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f[3][1005];

int main() {
    int n = 2;
    f[1][0] = 1;
    f[1][1] = 1;
    f[2][0] = 1;
    f[2][1] = 1;
    while(f[n % 3][0] < 1000) {//判断当前位数是否小于1000
        n += 1;
        int *a = f[n % 3], *b = f[(n - 1) % 3], *c = f[(n - 2) % 3];
        for(int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];//a[i][0]存位数，a[i][1]存值
        }
        a[0] = b[0];
        for(int i = 1; i <= a[0]; i++) {
            if(a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (a[0] == i);
        }
    }
    printf("%d\n", n);
    return 0;
}
