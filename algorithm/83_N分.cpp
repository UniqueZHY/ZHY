/*************************************************************************
	> File Name: 83_N分.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月09日 星期一 21时08分41秒
 ************************************************************************/
#include <iostream>
using namespace std;
//输入6 3
//left_num为n减去当前这一层数,还剩几 
//left_cnt为这是找的第几个，到m为止
int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {//递归出口
        if (left_num == 0) return 1;//都遍历完了并且数等于0
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    //每次搜索完一层后要减去当前层的值left_num - i
    //然后继续向下一层搜索,并且当前一查找到的个数加1left_cnt + 1
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}

//具体输出哪几种答案
/*#include <iostream>
using namespace std;

int num[10], cnt;

void p() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << '+';
        cout << num[i];
    }
    cout << endl;
}
int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) {
            p();
            return 1;
        }
        return 0;
    }
    int ans =  0;
    for (int i = s; i <= left_num; i++) {
        num[cnt] = i;
        cnt++;
        ans += func(i, left_num - i, left_cnt - 1);//
        cnt--;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}*/


//公式法
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int dfs(int n, int m) {
    if (n < m) return 0;
    if (n == m) return 1;
    if (m == 1) return 1; 
    if (n > m) return dfs(n - 1, m - 1) + dfs(n - m, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << dfs(n, m) << endl;
    return 0;
}*/
