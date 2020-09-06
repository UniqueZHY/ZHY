/*************************************************************************
	> File Name: 235_递归实现指数型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 16时22分16秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;
//num数组用来记录每次搜索的答案
int num[15], cnt ;//cnt是num的计数器
int n;//枚举上线
void p() {
    for (int i = 0;i < cnt ;i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
//用树的结构想，用数组想中下标cnt++, cnt--来模拟向下搜索和回溯的过程
void func(int s) {
    for (int i = s ;i <= n; i++) {//第一个数从s开始
        num[cnt++] = i ;//存进相应位置，相当于构造好树
        p();//打印
        func(i + 1);
        cnt--;//回溯，1234,cnt--,num[cnt] = 3,达到了回溯的目的
    }
}

int main(){
    cin >> n;
    func(1);
   return 0;
}

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void func(int ind, int n, int k, int *a) {
    if (ind == n) return ;
    for (int i = ind + 1; i <= n; i++) {
        a[k] = i;
        for (int j = 0; j <= k; j++) {
            j && cout << " ";
            cout << a[j];
        }
        cout << endl;
        func(i, n, k + 1, a);
    }
    return ;
}

int main() {
    int n;
    int a[10];
    cin >> n;
    func(0, n, 0, a);
    return 0;
}*/
