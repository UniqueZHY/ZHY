/*************************************************************************
	> File Name: 384_敲七.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 17时01分58秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

bool solve (int x) {
    if (x % 7 == 0) return false;
    int a;
    while (x) {
        a = x % 10;
        x /= 10;
        if (a == 7) return false;
    }
    return true;
}

int main() {
    queue <int> q;
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i <= m - 1; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = t; ; i++) {
        if (q.size() == 1) break;
        if (solve(i)) {
            q.push(q.front());
        }
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}
