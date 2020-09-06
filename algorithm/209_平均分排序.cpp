/*************************************************************************
	> File Name: 209_平均分排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 01时00分30秒
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
    int n;
    int a[105];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        cout << a[i] << endl; 
    }
    return 0;
}
