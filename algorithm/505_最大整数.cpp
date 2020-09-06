/*************************************************************************
	> File Name: 505_最大整数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时51分17秒
 ************************************************************************/
//本题可将数看成是字符串
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>//类
using namespace std;

int n;
string str[100005];

bool cmp(string a, string b) {//a是对象 string类中重载了+,就直接把两个字符串连起来
    return a + b > b + a;//排序方式为两个数组合起来更大，就用那种方式排
}

int main() {
    cin >> n;
    for  (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
