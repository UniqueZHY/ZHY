/*************************************************************************
	> File Name: 196_路飞爬楼梯.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 19时46分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int f(int n){
    if(n == 1) return 0;
    else if(n == 2 || n == 3 ||n == 4)  return 1;
    else if(n == 5 || n == 6 ) return 2;
    else return f(n - 2) + f(n - 3);
}    
int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
}
