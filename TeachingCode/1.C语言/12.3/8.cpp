/*************************************************************************
	> File Name: 8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 20时48分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int digits = 0;
    /*while(n) {
        n /= 10;
        digits += 1;
    }
    cout << digits << endl;
    digits = 0;*/
    do {
        n /= 10;
        digits += 1;
    }while (n);
    cout << digits << endl;
    return 0;
}
