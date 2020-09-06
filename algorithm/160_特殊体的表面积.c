/*************************************************************************
	> File Name: 160_特殊体的表面积.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 18时31分14秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define PI 3.14
int main(){
    double r, h;
    scanf("%lf %lf", &r, &h);
    double u, y, x, d, sum;
    u = PI * (r * r) / 2 + (4 * r * r / 2);
    y = PI * r * h;
    x = h * 2 * r;
    d = 2 * sqrt(2) * r * h;
    sum = 2 * u + y + x + d;
    printf("%.2lf", sum);
    return 0;
}
