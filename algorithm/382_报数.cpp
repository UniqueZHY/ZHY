/*************************************************************************
	> File Name: 382_报数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 16时36分56秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int ans = 0, n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        ans = (ans + m) % i;
    }
    cout << ans + 1 << endl;
    return 0;
}
/*
#define max_n 1000
int a[max_n + 5] = {1, 0};
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] + m) % i;
    }
    cout << a[n] + 1 << endl;
    return 0;
}
*/
/*int main() {
    queue <int> q;
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int now = 1;
    while (q.size() != 1) {
        if (now == m) {
            q.pop();
            now = 1;
        } else {
            q.push(q.front());
            q.pop();
            now++;
        }
    }
    cout << q.front() << endl;
    return 0;
}*/
