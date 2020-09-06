/*************************************************************************
	> File Name: 206_队列列求和.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 12时02分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct money{
    float m;
}a[35][35];
int main(){
    int n, m;
    float ave;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j].m;
        }
    }
    for(int j = 0; j < m; j++){
        ave = 0;
        for(int i= 0; i < n; i++){
            ave += a[i][j].m;
        }
        cout << ave << endl;
    }
}
