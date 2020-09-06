/*************************************************************************
	> File Name: 142.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 14时21分52秒
 ************************************************************************/

#include<stdio.h>
int prime(long int a){
    int res1 = 1;
    for(int i = 2; i < a; i++){
        if(a % i == 0) res1 = 0;
    }
    return res1;
}
int hui(long int b) {
    int res2 = 0;
    if(b / 10000 == b % 10 && b % 10000 / 1000 == b % 10000 % 1000 % 100 / 10){
         res2 = 1;
    }   
    return res2;
}
int main() {
    long int a, b, f = 0;
    scanf("%ld %ld", &a, &b);
    for(long int i = a; i <= b; i++){
        if(hui(i) == 1){
            if(prime(i) == 1){
                if(f == 1){
                    printf(" ");
                }

                printf("%ld", i);
                f = 1;
            }
        
         }
    }
    return 0;
}
