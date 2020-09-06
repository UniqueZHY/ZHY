/*************************************************************************
	> File Name: 47_01背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 20时04分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int all, n, w[105], v[105], ans[10005];

int main() {
    cin >> all >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = all; j > 0; j--) {
            if (j < w[i]) {
                break;
                //ans[j] = ans[j];
            } else {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
            }
        }
    }
    cout << ans[all] << endl;
    return 0;
}
