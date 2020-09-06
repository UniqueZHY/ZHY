/*************************************************************************
	> File Name: 204_计数质数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时14分49秒
 ************************************************************************/
int countPrimes(int n){
    int prime[2000000];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime[0];
}
