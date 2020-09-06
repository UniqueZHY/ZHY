/*************************************************************************
	> File Name: 469_进制转换1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 19时52分13秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
char str[40] = {0};
int ans[40] = {0};
typedef long long ll;
int main() {
    ll x;
    cin >> x;
    cin >> str;
    int len = strlen(str);
    //if (len > ans[0]) ans[0] = len;
    for (int i = 0; i < len; i++) {
        ans[len - i] = str[i] - '0';
    }
    for (int i = 1; i <= len; i++) {
        ans[i] = ans[i] * pow(x, i - 1);
    }
    int sum = 0;
    for (int i = 1; i <= len ; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
