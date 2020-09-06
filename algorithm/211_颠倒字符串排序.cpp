/*************************************************************************
	> File Name: 211_颠倒字符串排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 00时19分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct str{
    //char n[45];
    string name;
    char *h;
}a[35];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].name;
    }
    for(int i = 0; i < n; i++) {
        a[i].h = strrev(a[i].name);
        cout << a[i].h << " ";
        
    }
    return 0;
}
