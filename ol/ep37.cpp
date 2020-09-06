/*************************************************************************
	> File Name: 37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 20时00分07秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define max_n 2000000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1 , 1 , 0};

void init() {
    for (int i = 2;i <= max_n ;i++){
        if(!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0];j++) {
            if(prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return;
 }

int solve (int n) {
    int digit = floor(log10(n)) + 1;
    int h = pow(10 , digit - 1);
    int tmp = n;
    for (int i = 0;i <  digit - 1 ;i++) {
        tmp /= 10;
        if(is_prime[tmp]) return 0;
    }
    tmp = n;
    for (int i = 0;i < digit - 1;i++) {
        tmp %= h;
        if(is_prime[tmp]) return 0;
        h /= 10;
    }
    return 1;
}

int main() {
    init();
    int sum = 0 , flag = 11;
    for (int i = 1;i <= prime[0] && flag;i++) {
        if(prime[i] < 10) continue;
        if(!solve(prime[i])) continue;
         sum += prime[i];
         flag -= 1;
    }
    cout << flag << endl;
    cout << sum << endl;
    return 0;
}




/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 1000000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};
void init() {
    for (int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}
int fanzhuan(int n) {
    int tmp = n;
    int digit = floor(log(n)) + 1;
    int h = pow(10, digit);
    for (int i = 0; i < digit; i++) {
        tmp = tmp / pow(10, digit - i);
        if (!is_prime[tmp]) return 0;
    }
    return tmp;
}
int is_val(int n) {
    int a = n;
    int b = 0, sum = n;
    while (sum) {
        b = b * 10 + sum % 10;
        sum /= 10;
    }
    if (fanzhuan(a) == 1 && fanzhuan(b) == 1) return 1;
    return 0;
}
int main() {
    init();
    int flag = 11;
    int sum = 0;
    for (int i = 1; i <= prime[0] && flag; i++) {
        if (prime[i] < 10) continue;
        if (!is_val(prime[i])) continue;
        sum += prime[i];
        flag -= 1;
    }
    cout << sum << endl;
    return 0;
}*/
