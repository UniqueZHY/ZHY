/*************************************************************************
	> File Name: ep26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 20时27分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 1000
int r_len[max_n + 5] = {0};//用来存

int get_len(int d) {
    memset(r_len,0 , sizeof(r_len));
    int r = 1, t = 1;
    while (r) {//求下一次余数
        r *= 10;
        r %= d;
        t += 1;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
}

int main() {
    int d = 0, len = -1;
    for (int i = 2; i < max_n; i++) {
        int tmp = get_len(i);
        if (len < tmp) {
            len = tmp;
            d = i;
        }
    }
    cout << d << " " << len << endl;
    return 0;
}
