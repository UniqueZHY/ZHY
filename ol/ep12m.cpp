/*************************************************************************
	> File Name: ep12m.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 09时05分26秒
 ************************************************************************/
/*#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] + 1;
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            } else {
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    return ;
}
int main() {
    init();
    long long int n = 0, fac = 0;
    while (fac <= 500) {
        n += 1;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1) / 2 << endl;
    return 0;
}
*/


#include<iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] =  cnt[i] + 1;
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }

    return ;
}
int main() {
    init();
    long long n = 0, fac = 0;
    while (fac <= 500) {
        n += 1;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1) / 2 << endl;
    return 0;
}
