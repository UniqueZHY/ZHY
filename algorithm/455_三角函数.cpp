/*************************************************************************
	> File Name: 455_三角函数.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月14日 星期四 16时38分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
//#define max_n 1000000
typedef long long ll;
int a[5];
int gcd(ll x, ll y){
    ll r;
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
    int x, y, g;
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }    
    sort(a, a + 3);
    g = gcd(a[2], a[0]);
    x = a[0] / g;
    y = a[2] / g;
    cout << x << "/" << y;
    return 0;
}
