/*************************************************************************
	> File Name: 558_采药.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月23日 星期四 14时42分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int ans[1005], t[105], v[105];
int  T, m;

int main() {
    cin >> T >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = T; j > 0; j--) {
            if (j >= t[i]) ans[j] = max(ans[j], ans[j - t[i]] + v[i]);
        }
    }
    cout << ans[T] << endl;
    return 0;
}

/*int main() {
    cin >> T >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= T; j++) {
            if (j < t[i]) ans[i][j] = ans[i - 1][j];
            else ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - t[i]] + v[i]);
        }
    }
    cout << ans[m][T] << endl;
    return 0;
}*/
