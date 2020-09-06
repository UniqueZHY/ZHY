/*************************************************************************
	> File Name: 236_递归实现组合型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 21时39分59秒
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if (left == 0) {//已经为m个了后面的就不要了，直接输出
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = s; i <= n - left + 1; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);//每向下递归一次，left 减一个
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
