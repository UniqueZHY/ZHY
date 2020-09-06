/*************************************************************************
	> File Name: 375_奖学金.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 19时22分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Node {
    int id;
    int c;
    int m;
    int e;
    int all;
};
bool cmp1(struct Node x, struct Node y) {
    if (x.all == y.all) return x.c > y. c;
    return x.all > y.all;
}

int main() {
    struct Node a[305];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].all = a[i].c + a[i].m + a[i].e;
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < 5; i++) {
        cout << a[i].id << " " << a[i].all << endl;
    }
    return 0;
}
