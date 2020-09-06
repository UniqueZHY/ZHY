/*************************************************************************
	> File Name: ep12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月26日 星期四 20时47分09秒
 ************************************************************************/
#include<iostream>
using namespace std;
#define N 1000000

int prime[N + 5]= {0};
int f[N + 5] = {0};//存因子个数
int cnt[N + 5] = {0};//素因子幂次

void init() {
    for(int i = 2; i <= N; i++) {
        if(!prime[i]) { 
            prime[++prime[0]]= i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > N) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {//代表a和prime[j]不互素
                /*int a = i, cnt = 0;
                while(a % prime[j] == 0) a /= prime[j], cnt++;
                f[i * prime[j]] = f[i] /(cnt + 1) * (cnt + 2);//代表当前素因子幂次
                break;*/
                cnt[i * prime[j]] = cnt[i] + 1;
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            } else {//a和prime[j]互素
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    return ;
}

int main () {
    init();
    long long int n = 0, fac = 0;
    while(fac <= 500) {
        n += 1;
        if(n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else{
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1)/ 2 << endl;
    return 0;
}
