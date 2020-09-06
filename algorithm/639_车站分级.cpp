/*************************************************************************
	> File Name: 639_车站分级.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月30日 星期四 20时27分14秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, next;
};

edge edg[1000005];
int n, m, edg_cnt, head[1005], in_degree[1005], mark[1005][1005], ans[1005];

void insert_edg(int a, int b) {
    if (mark[a][b] == 1) return ;
    mark[a][b] = 1;
    edg[edg_cnt].to = b;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt;
    edg_cnt++;
    in_degree[b]++;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, num[1005], stop[1005] = {0};
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> num[j];
            stop[num[j]] = 1;
        }
        for (int j = num[0]; j <= num[t - 1]; j++) {
            if (stop[j] == 0) {
                for (int k = 0; k < t; k++) {
                    insert_edg(j, num[k]);
                }
            }
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    int fin = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            ans[e] = max(ans[e], ans[t] + 1);
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
        fin = max(fin, ans[t]);
    }
    cout << fin << endl;
    return 0;
}
