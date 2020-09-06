/*************************************************************************
	> File Name: 592_六十四进制.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时53分30秒
 ************************************************************************/
//由题意可知z64进制代表十进制数61 ，想找到有多少对数加起来进行&运算等于该值，首先应把z化为二进制即111101，由上图可知a b&运算若结果为z那么每一位是1 相应为才是1也就是说z二进制位上为1的位置ab的对应位置也应该为1 ，z二进制位为0的位置a b相应位置一个为0一个为1 挥着两个都为0，所以所求就等于z二进制表示0位的个数个3种 ，设0的个数为n ,所求即为3^n
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

char str[100005];
int num[64], num2[10] = {1, 2, 4, 8, 16, 32};
long long ans = 1;

int main() {
    cin >> str;
    for (int i = 0; i <= 63; i++) {
        int t = i;
        for (int j = 5; j >= 0; j--) {//求i二进制1的个数
            if (t >= num2[j]) {
                num[i]++;
                t -= num2[j];
            }
        }
    }
    for (int i = 0; str[i]; i++) {
        int t;
        if (str[i] >= '0' && str[i] <= '9') {
            t = str[i] - '0';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            t = str[i] - 'A' + 10;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            t = str[i] - 'a' + 36;
        } else if (str[i] == '-') {
            t = 62;
        } else {
            t = 63;
        }
        t = 6 - num[t];//2的6次幂是64 故只有6位,用总位数-1的个数就是0的个数
        for (int i = 0; i < t; i++) {
            ans = ans * 3 % 1000000007;
        }
    } 
    cout << ans << endl;
    return 0;
}
