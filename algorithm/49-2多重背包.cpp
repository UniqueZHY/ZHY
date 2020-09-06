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

int ans[100005];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = V; j >= v; j--) {
            for (int k = 1; k <= s && k * v <= j; k++) {
                ans[j] = max(ans[j], ans[j - v * k] + k * w);
            }
        }
    }
    cout << ans[V] <<endl;
    return 0; 
}

