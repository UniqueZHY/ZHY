/*************************************************************************
	> File Name: 202_身高排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 11时03分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct height{
    int h;
    int num;
}a[1005];
bool cmp(height x, height y){
    if(x.h == y.h){
        return x.num < y.num;
    }
    return x.h < y.h;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].h;
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        i != 1 && cout << " ";
        cout << a[i].num ;
    }
    return 0;
}
