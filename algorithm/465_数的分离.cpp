/*************************************************************************
	> File Name: 465_数的分离.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 14时51分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
char func(string str, int length, int x){
    ll flag = 0;
    //return str[length - x];
    for (ll j = length - 1; j >= 0; j--){
        flag++;
        if(flag == x){
            return str[j];
        }
    }
}
int main(){
    int k;
    char res;
    string str;
    cin >> str;
    int len  = str.length();
    cin >> k;
    res = func(str, len, k);
    cout << res;

    return 0;
}
