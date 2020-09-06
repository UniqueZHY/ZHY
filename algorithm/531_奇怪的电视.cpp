/*************************************************************************
	> File Name: 531_奇怪的电视.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 18时46分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
    int status, step;
};
int n, num[25], arr[25][25], check[2200000];

void init() {
    int t = 1;
    for (int i = 0; i < 21; i++) {
        num[i] = t;
        t *= 2;
    }
}

int main() {
    init();
    cin >> n;
    int start_status = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) start_status += num[i];//初始状态
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];//会有几个按钮被弹回来
        for (int j = 1; j <= arr[i][0]; j++) {
            cin >> arr[i][j];
            arr[i][24] += num[arr[i][j]];//按下第i个按钮后，加上其他按钮的状态
        }
    }
    queue <node> que;
    que.push({start_status, 0});
    check[start_status] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.status == 8) {//终点也就是只有按钮3 按下去了01000
            cout << temp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if ((temp.status & num[i]) == 0) {//该按钮没被按下去
                int status_temp = temp.status + num[i];
                //按i后被弹出来的按钮的二进制取反 那么应被弹出去的按钮所对应的二进制位就应该是0 在&上当前位置那么，应被弹出按钮二进制位置一定会变为0
                status_temp &= ~(arr[i][24]);//按i按钮后的状态
                if (!check[status_temp]) {//看看是否遍历过
                    check[status_temp] = 1;
                    que.push({status_temp, temp.step + 1});
                }
            }
        }
    }
    return 0;
}
