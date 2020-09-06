/*************************************************************************
	> File Name: 376_机器翻译.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 13时16分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 1000
int a[max_n + 5];
int b[max_n + 5];
int m, n, l, r, ans, x;
int main() {
    cin >> m >> n;
    for (int i  =0; i < n; i++) {
        cin >> x;
        if (a[x] == 0) {
            ans++;
            r++;
            b[r] = x;
            a[x] = 1;
            if (r > m) {
                l++;
                a[b[l]] = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
