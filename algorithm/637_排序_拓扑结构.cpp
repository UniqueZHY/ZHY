/*************************************************************************
	> File Name: 637.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年07月30日 星期四 20时11分19秒
 ************************************************************************/
//本题分为三种情况 普通 有环和有解
//普通就是值有多个答案 入度为0的点超过两个
//偷换的判断就是指都已经遍历完了之后还是有超过两个以上的入度不为0 ，说明成环了没有被访问到 视为我们只会访问入度为0 你的点
//取出普通和有换的情况剩下的就是有解的情况了
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int to, next;
};

edge edg[10000];
int n, m, edg_cnt, ans_cnt, head[30], in_degree[30];
char ans[30];

void insert_edg(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    head[a] = x;
    edg_cnt = x + 1;
    in_degree[b]++;
}

int check() {
    int temp_in[30];//定义临时入度
    ans_cnt = 0;//答案计数器清零
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        temp_in[i] = in_degree[i];
        if (temp_in[i] == 0) {
		//说明是起点
            que.push(i);
        }
    }
    int f1 = que.size(), f2 = 0; //起点的点的数量 如果不为1 说明答案不确定
    while (!que.empty()) {
        int t = que.front();
        int f3 = 0;
        que.pop();
        ans[++ans_cnt] = t + 'A' - 1;//变回原来的字符
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            temp_in[e]--;//临时入度减1
            if (temp_in[e] == 0) {
                if (f3 == 1) {
                    f3 = 2; //有两个以上的入度为0的点f3 为 2 时 说明答案不确定
                } else if (f3 == 0) {
                    f3 = 1;
                }
                que.push(e);
            }
        }
        if (f3 == 2) {
            f2 = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (temp_in[i] != 0) {
			//成环了
            return 1;
        }
    }
    if (f1 != 1 || f2 == 2) {
        //起点不止一个或者成环了没求出答案
		return 0;
    }
    return 2;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> b;//输入格式为a < b 第一个b就是代表输入<
        insert_edg(a - 'A' + 1, b - 'A' + 1, i);
        int t = check(); //返回0普通情况 返回1成环 返回2 正确答案
        if (t == 1) {
            cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            return 0;
        } else if (t == 2) {
            cout << "Sorted sequence determined after " << i + 1 << " relations: ";
            for (int i = 1; i <= ans_cnt; i++) {
                cout << ans[i];
            }
            cout << "." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl;
    return 0;
}
