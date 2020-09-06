/*************************************************************************
	> File Name: 442_走楼梯.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 19时19分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int main(){
    int a[35];
    int n;
    a[1] = 1;
    a[2] = 2;
    cin >> n;
    for(int i = 3; i <= n; i++){
        a[i] = a[i - 2] + a[i - 1];
    }
    for(int i = 1; i <= n; i++){
        i != 1 && cout << " ";
        cout << a[i];
    }
}
