/*************************************************************************
	> File Name: 35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 18时57分39秒
 ************************************************************************/
#include<iostream>
#include<cmath>
#define max_n 1000000
//先找到1000以内的素数在再数组里面找符合条件的
using namespace std;
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1, 1, 0};

void init(){
    for(int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    } 
    return ;
}

int is_val(int n) {
    int digit = floor(log10(n)) + 1;//位数
    int h = (int)pow(10, digit - 1);
    int tmp = n;
    for (int i = 1; i < digit; i++) {
        tmp = (tmp % 10) * h + tmp / 10;
        if (is_prime[tmp]) return 0;
    }
    return 1;
}

int main() {
    init();
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (!is_val(prime[i])) continue;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
