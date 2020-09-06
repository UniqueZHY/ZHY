/*************************************************************************
	> File Name: 17.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 10时20分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int js(int n) 
{
    if(n<8)return n;
    else return n%8+10*(js(n/8));
}
int main() 
{
    int n, sum;
    cin>>n;
    int a;
    a = js(n);
    while(a){
        if(a % 10 == 7)
        sum++;
        a /= 10;
    }
    cout << sum << endl;
    return 0;
}
