/*************************************************************************
	> File Name: ep14-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 14时12分21秒
 ************************************************************************/
#include<stdio.h>
#define max_n 1000000
#define size 100
int keep[max_n + 5] = {0};

typedef long long ll;

ll get_len(ll  n) {
    if (n == 1) return 1;
    if (n <= max_n && keep[n]) return keep[n];
    ll ret = 0;
    if (!(n & 1)) ret =  get_len(n >> 1) + 1;
    else ret = get_len(3 * n + 1) + 1;
    if (n <= max_n) keep[n] = ret;
    return ret;
}

int main() {
    ll ans = 0, len = 0;
    for (ll i = 1; i < max_n; i++) {
        ll temp = get_len(i);
        if (temp > len) {
            ans = i;
            len = temp;
        }
    }
    printf("num = %lld, len = %lld\n", ans, len);
    return 0;
}
