/*************************************************************************
	> File Name: 675_人去达人.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月29日 星期三 19时07分13秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct edge {
    int to, val, next;

};

edge edg[100005];
int n, m, c, head[100005], ans[100005], in_degree[100005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> c >> c;//最后一个c代表m
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
    }
    for (int i = 0; i < c; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].to = b;
        edg[i].val = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        //遍历入度
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            ans[e] = max(ans[e], ans[t] + edg[i].val);
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
