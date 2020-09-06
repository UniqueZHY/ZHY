/*************************************************************************
	> File Name: 204_方阵对角线.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月20日 星期三 23时29分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct student{
    int h = 0;
    int l = 0;
    int p = 0;
}a[35][35];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j].p;
            a[i][j].h = i;
            a[i][j].l = j;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j].h == a[i][j].l){
                cout << a[i][j].p << endl;
            }
        }
    }
}
