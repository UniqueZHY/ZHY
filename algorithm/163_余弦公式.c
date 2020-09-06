/*************************************************************************
	> File Name: 163_余弦公式.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 23时54分11秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
const double PI = 4.0 * atan(1.0);
int main() {
    double a, b;
    double  angle, ans;
    scanf("%lf %lf %lf", &a, &b, &angle);
    ans = sqrt(a * a + b * b - 2 * a * b * cos(angle * PI / 180));
    printf("%.6lf", ans);
    return 0;
}
