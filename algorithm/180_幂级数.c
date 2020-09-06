/*************************************************************************
	> File Name: 180_幂级数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 22时23分22秒
 ************************************************************************/

#include<stdio.h>
typedef long long ll;
int pow(ll a, ll x){
    ll ans = 1;
    while(x){
        if(x & 1){
            ans = ans * a;
        }
        a *= a;
        x >>= 1;
    }
    return ans;
}
int main() {
    ll n; 
    scanf("%ld", &n);
    printf("%ld", pow(2, n));

    return 0;
}
