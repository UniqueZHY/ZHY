/*************************************************************************
	> File Name: 587_环.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时11分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int a, b, c, d = 0;
    cin >> a >> a >> b >> c;
    if (a > b) d++;
    if (b > c) d++;
    if (c > a) d++;
    if (d == 2) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
