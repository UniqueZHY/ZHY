/*************************************************************************
	> File Name: 380_大统领投票.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 18时45分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Node {
    int num;
    char str[1005];
};
 
int cmp (struct Node a, struct Node b) {
    int x = strlen(a.str);
    int y = strlen(b.str);
    if (x - y) return x > y;
    return a.str > b.str;
}
int main() {
    struct Node a[105]; 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].str;
        a[i].num = i;    
    }
    sort(a, a + n, cmp);
    //cout << a[0].num + 1<< endl;
    //cout << a[0].str << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i].num + 1 << " " << a[i].str << endl;
    }
    return 0;
}
