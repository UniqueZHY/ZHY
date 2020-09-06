/*************************************************************************
	> File Name: 165_勾股定理.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 17时28分03秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
    long long c, a, f = 0;
    double  x;
    scanf("%d", &c);
    for(long long i = 1; i < c ; i++){
        x = sqrt(c * c - i * i);
        a = (long long)x;
        if(a * a == x * x){
            f++;
            printf("%d %d\n", x, i);
        }
    }
    printf("%d", f / 2);
    return 0;
}
