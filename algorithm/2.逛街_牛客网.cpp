/*************************************************************************
	> File Name: 2.逛街_牛客网.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 20时00分05秒
 ************************************************************************/
//求站在不同楼能看见桥后楼的个数(包括当前的楼),搞得楼会吧低的楼盖住，低的楼就看不见了
#include <iostream>
#include <stack>
using namespace std;

int n, num[10005], ans1[100005], ans2[100005];

int main() {
    stack<int> qian, hou;
    cin >> n;
    qian.push(999999999);
    hou.push(999999999);
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        ans1[i] = qian.size();
        while (qian.top() <= num[i]) {
            //维护一个递减的单调队列
            qian.pop();
        }
        qian.push(num[i]);
    }
    for (int i = n; i >= 1; i--) {
        ans2[i] = hou.size();
        while (hou.top() <= num[i]) {
            hou.pop();
        }
        hou.push(num[i]);
    }
    for (int i = 1;i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << ans1[i] + ans2[i] - 1;
    }
    cout << endl;
    return 0;
}
