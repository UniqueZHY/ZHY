/*************************************************************************
	> File Name: 156_数值计算.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 14时44分07秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int prime(int x) {
    int pans = 1;
    for(int i = 2; i < x; i++){
        if(x % i == 0) {
            pans = 0;
            break;
        }
    }
    return pans;
}
int w(int a) {
    int b;
    int wans = 0;
    b = sqrt(a);
    if(b * b == a){
        wans = 1;
    }
    return wans;
}
int main() {
    int a, b, q, s, f = 0;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++) {
        q = i % 100;//后两位
        s = i / 100;//前两位
        if(prime(i) == 1 && w(q) == 1 && w(s) == 1){
            printf("%d\n", i);
            f++;
        }
    }       
    printf("%d", f);
    return 0;
}
