/*************************************************************************
	> File Name: 牛客网解压字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 19时23分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

//HG[3|B[2|AC]]F => HGBACACBACACBACACF
//数字意为后面字符串重复个数 |为分隔符

int main() {
    string s; 
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') {
            char t[1000005] = {0};
            int cnt = 0;
            while (sta.top() != '|') {
        //找到右中括号位置的第一个人待重复字符串并存储到t中
                t[cnt++] = sta.top();
                sta.pop();
            }
            sta.pop();
            int times = 0, ind = 1;
            while (sta.top() !='[') {
                //找到当前待重复字符串的重复次数
                times += (sta.top() - '0') * ind;
                ind *= 10;//确定重复数的十位数
                sta.pop();
            }
            sta.pop();
            for (int j = 0; j < times; j++) {
                for (int k = cnt - 1; k >= 0 ; k--) {
                    sta.push(t[k]);
                }
            }
        } else {
            sta.push(s[i]);
        }
    }
    char ans[100005]  = {0};
    int cnt = 0;
    while (!sta.empty()) {
        ans[cnt++] = sta.top();
        sta.pop();
    }
    for (int i = cnt - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
