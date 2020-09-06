/*************************************************************************
	> File Name: 205_队列平均数.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 00时29分40秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct queue{
    int p;
}a[35][35];
int main(){
    int n, m;
    double ave = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j].p;
        }
    }
    int i, j;
    for(i = 0; i < n; i++){
        ave = 0;
        for(j = 0; j < m; j++){
            ave += a[i][j].p;
           // cout << ave << endl;
        }
        cout << fixed << setprecision(6)<< ave / m << endl;
    }
    return 0;
}
