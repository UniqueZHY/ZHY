/*************************************************************************
	> File Name: 673_奇怪的桌游.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月29日 星期三 20时42分10秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct edge {
    int to, next;
};

struct node {
    int now;
    bool operator<(const node & b) const {
        return this->now > b.now;
    }
};

edge edg[100005];
int n ,m , head[100005], in_degree[100005], in_degree2[100005];

int best() {
    int ans = 0, mmax = 0;
    priority_queue<node> que;
    //入度为0的点加到里面
    for (int i = 1; i <= n; i++) {
        in_degree2[i] = in_degree[i];
        if (in_degree2[i] == 0) {
            que.push((node){i});
        }
    }
    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (t.now > mmax) {
            ans++;
            mmax = t.now;
        }
        for (int i = head[t.now]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree2[e]--;
            if (in_degree2[e] == 0) {
                que.push((node){e});
            }
        }
    }
    return ans;
}

int worst() {
    int ans = 0, mmax = 0;
    set<node> se;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            se.insert((node){i});
        }
    }
    while (!se.empty()) {
        //拿到集合第一个元素
        node t = *se.begin();
        if (t.now > mmax) {
            for (set<node>::iterator it = se.begin(); it != se.end(); it++) {
                t = *it;
                if (t.now < mmax) {
                    break;
                } else {
                    t = *se.begin();
                }
            }
        }
        se.erase(t);
        if (t.now >mmax) {
            ans++;
            mmax = t.now;
        }
        for (int i = head[t.now]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e]--;
            if (in_degree[e] == 0) {
                se.insert((node){e});
            }
        }
    }
    return ans;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    int ans1 = best();
    cout << ans1 << endl;
    int ans2 = worst();
    cout << ans2 << endl;
    return 0;
}
