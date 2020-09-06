/*************************************************************************
	> File Name: ep10-1m.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月20日 星期五 12时50分44秒
 ************************************************************************/

#include<iostream> 
using namespace std;
#define max_n 2000000
int prime[max_n + 5];

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;        
        }
            
    }
    return ;

}

int main() {

    init ();
    int m, n;
    long long sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= prime[0] && prime[i] < n; i++) {
        if(prime[i] >= m) cout << prime[i] << endl;    
    }
    return 0;

}
