/*************************************************************************
	> File Name: b.拓扑排序代码实现.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月29日 星期三 22时11分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct edge {
    //边集
    int to, next;
};

edge edg[50];
int n ,m , head[50]/*链式前向星*/, in_degree[50]/*入度*/;

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;//统计入度 以b为终点的点入度加1
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            //遍历找到入度为0的点作为起点
            que.push(i);
        }
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        cout << temp << " ";
        for (int i = head[temp]; i!= -1; i = edg[i].next) {
            //找到当前起点的每一条边
            int e = edg[i].to; 
            in_degree[e]--;//以当前点的每一条边入度减1
            if (in_degree[e] == 0) {
                //入度为0 加到队列里去
                que.push(e);
            }
        }
    }
    return 0;
}
