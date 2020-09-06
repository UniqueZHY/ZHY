/*************************************************************************
	> File Name: 589_看电影.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时35分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int n, k, id;
    cin >> n >> k >> id;
    if (n == k) cout << "1/1" << endl;
    else if (k == 0) cout << "0/1" << endl;
    else {
        int c = gcd(n, k);
        cout << k / c << "/" << n / c << endl;
    }
    return 0;
}
