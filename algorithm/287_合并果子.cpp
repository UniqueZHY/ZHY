/*************************************************************************
	> File Name: 287_合并果子.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月05日 星期四 20时58分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue <int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    while (n--) {
        int v;
        cin >> v;
        q.push(v);
    }
    int ans = 0;
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}

