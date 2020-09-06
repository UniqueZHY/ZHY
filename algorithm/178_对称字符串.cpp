/*************************************************************************
	> File Name: 178_对称字符串.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 20时36分18秒
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
    string a[25];
    string b;
    string c = "B";
    cin >> n;
    a[1] = "A";
    if(n == 1) b = "A";
    for(int i = 2; i <= n; i++){
        b = a[i - 1] + (c[0]++) + a[i - 1];
        a[i] = b;
    }
    cout << b << endl;
    return 0;
}
