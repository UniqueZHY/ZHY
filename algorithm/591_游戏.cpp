/*************************************************************************
	> File Name: 591_游戏.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 20时32分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0) {//a如果在mid左边就选a右边的 a如果在mid右边就选a左边的
        int mid = n / 2;
        if (m <= mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    } else {//奇数个a有可能指向中间
        int mid = (n + 1) / 2;
        if (m < mid) cout << m + 1 << endl;
        else cout << m - 1 << endl;
    }
}
