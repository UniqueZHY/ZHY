/*************************************************************************
	> File Name: 2.建路灯_牛客.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月19日 星期三 16时21分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int mian()  {
    int n;
    cin >> n;
    while (n--) {
        int t, ans = 0;
        string s;
        cin >> t >> s;
        for (int i = 0; i < t; i++) {
            if (s[i] == '.') {
                ans++;
                i += 2;
            }
        }
        cout << ans << endl;
    }
}
