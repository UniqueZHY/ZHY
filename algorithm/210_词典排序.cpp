/*************************************************************************
	> File Name: 210_词典排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 00时09分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct letter{
    string l;
}a[30];
bool cmp(letter x, letter y){
    return x.l < y.l;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].l;
    }

    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++){
        i != 0 && cout << " ";
        cout << a[i].l;
    }
    return 0;
}
