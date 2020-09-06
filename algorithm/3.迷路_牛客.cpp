/*************************************************************************
	> File Name: 3.迷路_牛客.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月19日 星期三 16时29分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int main()  {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ans--;
        } else {
            ans++;
        }
    }
    
    if (ans == 0) {
        cout << "N" << endl;
    } else if (ans == 1) {
        cout << "E" << endl;
    } else if (ans == 2) {
        cout << "S" << endl;
    }  else {
        cout << "W" << endl;
    }
    return 0;
}

