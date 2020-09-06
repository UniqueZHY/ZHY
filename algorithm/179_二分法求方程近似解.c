/*************************************************************************
	> File Name: 179_二分法求方程近似解.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 20时02分17秒
 ************************************************************************/

/*#include <stdio.h>
#include <math.h>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d%d", &p, &q);
    printf("%.4f\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double a = -20, b = 20, m = 0;
    while (fabs(func(p, q, m)) > EPSILON) {
        if (func(p, q, m) * func(p, q, a) < 0) {
            b = m;
        } else {
            a = m;
        }
        m = (a + b) / 2;
    }
    return m;
}

double f(int p, int q, double x) {
    return p * x + q;
}*/
#include<stdio.h>
#include<math.h>
#define EPSILON 1e-7 
double bisection(int p, int q, double(*func)(int, int, double)){
    int a = -20; 
    int b = 20;
    int m = 0;
    while(fabs(func(p, q, m)) > EPSILON){
        if(func(p, q , m) * func(p, q, a) < 0){
            b = m;
        } else {
            a = m;
        }
        m = (a + b) / 2;
    }   
    return m;
}
double f(int p, int q, double x){
    return p * x + q;
}
int main() {
    int p, q;
    scanf("%d %d", &p, &q);
    printf("%.4d", bisection(p, q, f));
    return 0;
}
