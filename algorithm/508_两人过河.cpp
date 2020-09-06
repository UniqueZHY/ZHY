/*************************************************************************
	> File Name: 508_两人过河.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 19时04分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, num[1005], ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    //主要用两种策略挨个送，每次送走两个最慢的人直到剩下1，2或3个人
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {//剩一个人
            ans += num[0];
            break;
        }
        if (i == 1) {//剩两个人
            ans += num[1];
            break;
        }
        if (i == 2) {//剩三个人
            ans += num[0] + num[1] + num[2];
            break;
        }
        //两种策略取最小值的办法送走当前最慢的两个人
//策略一，最快+次快先走，最块回来，最慢+次慢去，次快回来
//策略二，最慢+次慢先走，最快回来，次慢+最快去，最快回来
                  //次快  + 最快   + 最慢   + 次快    最慢   + 最快   + 次慢       + 最快
        ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);
    }
    cout << ans << endl;
    return 0;
}
