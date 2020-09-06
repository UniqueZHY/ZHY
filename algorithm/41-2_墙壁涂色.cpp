/*************************************************************************
	> File Name: 41_墙壁涂色.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 20时26分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 1000

struct BigInt : public vector<int> {//大整数类
    BigInt(int x = 0) {//构造函数，使int可以赋值给大整数类型
        push_back(x);
        normal();//处理进位
    }

    BigInt operator*(int x) {
        //重载乘法运算符，为了支持68行的大整数乘法
        BigInt ret(*this);
        for (int i = 0; i < ret.size(); i++) ret[i] *= x;
        ret.normal();
        return ret;
    }

    BigInt operator+(const BigInt &a) {
        //重载加法运算符，为了支持68行的大整数加法
        BigInt ret(*this);
        for  (int i = 0; i < a.size(); i++) {
            if (i < ret.size()) ret[i] += a[i];//如123 存储就是321
            else ret.push_back(a[i]);//超过了最高位就在加一为
        }
        ret.normal();
        return ret;
    }

    void normal() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[MAX_N + 5];


ostream &operator<<(ostream &out, const BigInt & a) {//重载运算符
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];//倒着输出大整数
    }
    return out;
}

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = (k - 1) * k;
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}
