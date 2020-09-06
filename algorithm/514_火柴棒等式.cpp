/*************************************************************************
	> File Name: 514_火柴棒等式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 19时35分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[10] = {
    6, 2, 5, 5, 4,
    5, 6, 3, 7, 6 };
int solve(int x) {
    int sum = 0, a;
    if (!x) return 6;//如果为0就直接返回0的火柴棒数
    while (x) {
        a = x % 10;
        sum += arr[a];
        x /= 10;
    }
    return sum;
}
int main() {
    int n, a, b, c;
    cin >> n;
    n -= 4;
    int cnt = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            a = solve(i);
            b = solve(j);
            c = solve(i + j);
            if (a + b + c == n) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
