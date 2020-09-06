/*************************************************************************
	> File Name: 392_丢瓶盖.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月29日 星期三 18时07分09秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] >= mid) {
            cnt++;//用来记录瓶盖数
            now = i;//now用来记录上一个瓶盖位置
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int cnt = check(mid);
        if (cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0];
    cout << func() << endl;
    return 0;
}


/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define max_n 100000005
int A, B;
int a[max_n];

int is_val(int x) {
    int first = 0;
    for (int i = 1; i < B; i++) {
        int second = first + 1;
        while (second < A && a[second] - a[first] < x) {
            second++;
        }
        if (second == A) return 0;
        first = second;
    }
    return 1;
}


int main() {
    cin >> A >> B;
    for (int i = 0 ; i < A; i++) {
        cin >> a[i];
    }
    sort(a, a + A);
    int l = 0, r = a[A - 1], mid;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (is_val(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}*/
