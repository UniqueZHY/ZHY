/*************************************************************************
	> File Name: ep39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 15时09分11秒
 ************************************************************************/  
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<iomanip>
#define max_n 1000
int cnt[max_n + 5] = {0};//记录构成三角形的可能
using namespace std;

int gcd (int a , int b) {
    return (b ? gcd (b , a % b) : a);
}

int main() {
    for (int n = 1 ; n <= 32 ;n++) {
        for (int m = n + 1 ;m <= 32 ;m++) {
            if (gcd(m ,n) != 1) continue;//对偶逻辑
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n ;
            for (int p = a + b + c ; p <= 1000 ;p += (a + b + c)) {
                cnt[p] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= max_n ;i++) {
        if (cnt[i] > cnt[ans]) ans = i; 
    }
    cout << ans << endl;
    return 0;
}
