/*************************************************************************
	> File Name: 15.素数筛.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 20时49分49秒
 ************************************************************************/
#include<stdio.h>
#define max_n 1000

/*int prime[max_n + 5] = {0};

void init_prime() {
    prime[0] = 1, prime[1] = 1;
    for (int i = 2; i <= max_n; i++){
        if (prime[i]) continue;
        for (int j = i * i; j <= max_n; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}*/
//void init_prime() {}
int prime(int n) {
    if (n <= 1) return 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i) continue;
        return 1;
    }
    return 0;
}
int main() {
    //init_prime();
    int n;
    while(~scanf("%d", &n)) {
        printf("%s\n", prime(n) ? "no":"yes");
        //printf("%s\n", prime[n]?"no":"yes");
    }
    return 0;
}
