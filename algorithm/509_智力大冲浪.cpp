/*************************************************************************
	> File Name: 509_智力大冲浪.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 23时39分33秒
 ************************************************************************/
//只需将每件任务对应的扣得钱进行一个排序，把扣得钱多的任务先做完，再定义一个标记数组，用来标记某个时间段上是否有任务正在进行，如果有那就不能将该任务放在当前时间段上，因为要在限定的前几个小时内昨晚所以应该在做钱多任务的基础上，把其安排在最晚的时间做，例4 70 梭子在第四个小时做该任务就可，这样就留下前三个空闲时间可以做别的任务
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int t, m;
};

int n, m, mark[10000] = {1};
bool cmp(node x, node y) {
    if (x.m == y.m) return x.t > y.t;
    return x.m > y.m;
}
node game[505];

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> game[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> game[i].m;
    }
    sort(game, game + n, cmp);
    for (int i = 0; i < n; i++) {
        for (int j = game[i].t; j >= 0; j--) {
            if (!mark[j]) {
                mark[j] = 1;
                break;
            }
            if (!j) m -= game[i].m;
        }
    }
    cout << m << endl;
    return 0;
}
