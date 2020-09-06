/*************************************************************************
	> File Name: 458_年龄排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 23时18分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct person{
    string name;
    string gender;
    int y;
    int m;
}a[105];
bool cmp(person x, person y){
    if(x.y == y.y) return x.m > y.m;
    return x.y > y.y;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].gender >> a[i].y >> a[i].m;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++){
        cout << a[i].name << " " << a[i].gender << " " << a[i].y << " "<<a[i].m << endl;
    }
}
