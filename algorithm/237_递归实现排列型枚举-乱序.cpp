/*************************************************************************
	> File Name: 237_递归实现排列型枚举-乱序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 21时42分28秒
 ************************************************************************/
#include <iostream>
using namespace std;

int n, num[15], cnt, mark[15];
// num用来存每一次的答案，mark是标记数组，防止重复
void func(int left) {
    if (left == 0) {//已经把本次搜索的数已经确定好的
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {//没用过，可以用
            mark[i] = 1;
            num[cnt] = i;
            cnt++;
            func(left - 1);
            cnt--;
            mark[i] = 0;//还原回去
        }
    }
}

int main() {
    cin >> n;
    func(n);
    return 0;
}
