/*************************************************************************
	> File Name: 243_秦鹏的教学评估.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 18时55分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//找奇数点的位置

#define MAX_N 200000
struct Data{
    int s, e, d, c;
} arr[MAX_N + 5];
int n;

int check(int pos) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].s > pos) continue;
        if (arr[i].e <= pos) {
            cnt += arr[i].c;
            continue;
        }
        cnt += (pos - arr[i].s) / arr[i].d + 1;
    }
    return cnt;
}

int bs(int l, int r) {
    if (l == r) return l;
    int mid = ((l ^ r) >> 1) + (l & r);
    if (check(mid) & 2) return bs(l, mid);
    return bs(mid + 1, r);
}
void solve() {
    int l, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        arr[i].c = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if (i == 0) l = arr[i].s, r = arr[i].e;
        l = min(arr[i].s, l);
        r = min(arr[i].e, r);
    }
    int pos = bs(l, r);
    if (cnt % 2) {
        cout << pos << " " << cnt << endl;
    } else {
        cout << "Poor QIN TENG:(" << endl;
    }

}

int main() {
    int tcase;
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}
