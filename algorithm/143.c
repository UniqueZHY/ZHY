/*************************************************************************
	> File Name: 143.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 19时24分55秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int prime(int p){
    int x = 1;
    for(int i = 2; i < p; i++){
        if(p % i == 0){
          x = 0; 
          break;
        }
    }
    return x;
}
int s(int w){
    int e;
    int r;
    e = sqrt(w);
    if(e * e != w){
        r = 0;
    }
    else r = 1;
    return r;
}
int main(){
    int a, b, z, h, f = 0;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++){
        z = ((i / 1000 ) * 10) + (i % 1000 / 100);
        h =((i % 1000 % 100 / 10) * 10) + (i % 10);
        if(i % 6 == 0){
            if(prime(z) == 1){
                if(s(h) == 1){
                    printf("%d\n", i);
                    f++;
                }
            }
         }
    }
    printf("%d\n", f);
    return 0;
}
