/*************************************************************************
	> File Name: 463_桌面窗体重叠.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 14时41分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int l, r, u, d, ans;
    int l1, r1, u1, d1;
    cin >> l >> r >> u >> d;
    cin >> l1 >> r1 >> u1 >> d1;
    if(d < u1 || d1 < u || r < l1 || r1 < l) ans = 0;
    else ans = ((r < r1 ? r : r1) - (l > l1 ? l : l1)) * ((d < d1 ? d : d1) - (u > u1 ? u : u1));
    cout << ans << endl;
    return 0;
}
