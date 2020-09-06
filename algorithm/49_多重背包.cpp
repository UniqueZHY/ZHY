/*************************************************************************
	> File Name: 49_多重背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时44分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int all, n, ind, w[100005], ans[100000], v[100005];
int main() {
    cin >> all >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 0; i < z; i++) {
            ind++;//拆开成一个一个的，Ind就记录个数
            w[ind] = x;
            v[ind] = y;
        }
    }//相当于ind个物品，每个价值在v[ind]中重量在w[ind]中
    for (int i = 1; i <= ind; i++) {//像解决01背包一样，解决ind个物品
        for (int j = all; j >= w[i]; j--) {
            ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}
