/*************************************************************************
	> File Name: 桶排.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 12时36分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int score[101];

int main() {
    int m, n;
    cin >> m;
    memset(score, 0, sizeof(score));
//memset()的作用是在一段内存块中填充某个给定的值。因为它只能填充一个值，所以该函数的初始化为原始初始化，无法将变量初始化为程序中需要的数据。用memset初始化完后，后面程序中再向该内存空间中存放需要的数据。
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        score[x] += 1;
    }
    cin >> n;
    for (int i = 100; i >= 0; i--) {
        if (score[i] >= n) {
            cout << score[i] << endl;
            break;
        }
    }
    return 0;
}
