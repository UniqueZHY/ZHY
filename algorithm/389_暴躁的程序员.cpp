/*************************************************************************
	> File Name: 389_暴躁的程序员.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时52分27秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int func2(int len) {//当前值能安排多少人
    int cnt = 1, now = 0;//人数，上一个人的位置
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] >= len) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 0, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int cnt = func2(mid);
        //当前mid可能是最终答案,1111111000000找最后一个1
        if (cnt >= m) l = mid;
        //小于m一定不是所求，故r = mid-1
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    sort(num, num + n);
    cout << func() << endl;

    return 0;
}
