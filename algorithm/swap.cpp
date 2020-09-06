/*************************************************************************
	> File Name: swap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 18时53分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define swap(a, b) {\
 __typeof(a) __temp = a;\
    a = b, b = __temp;\
 }
int main() {
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << b << endl;
}
