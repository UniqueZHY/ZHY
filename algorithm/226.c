/***************************************************************mZ********
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 16时06分55秒
 ************************************************************************/

#include<stdio.h>
int pow_mod(long long a, long long b, long long q) {
    int ans = 1;
    int base = a % q;
    while(b) {
        if(b & 1) ans = (base * ans) % q;
        base = (base * base) % q;
        b >>= 1;
    }
        return ans;
    }
 int main(){
    long long x, n, res, c;
    scanf("%lld %lld %lld", &x, &n, &c);
    res = pow_mod(x, n, c);
    printf("%lld", res);
    return 0;   
}
