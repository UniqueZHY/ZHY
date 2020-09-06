/*************************************************************************
	> File Name: 518_金币.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 17时05分33秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int x;
    cin >> x;
    int sum = 0;
    int y = 1;
    while (x) {
        for (int i = 1; i <= y; i++) {
            sum += y;
            x--;
            if (x == 0) break;
            //cout << y << " " <<  sum << endl;
        }
        //x--
        y++;
        if (x == 0) break;
    }
    cout << sum << endl;
    return 0;
}
