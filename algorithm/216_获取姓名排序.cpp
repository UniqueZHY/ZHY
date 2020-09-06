/*************************************************************************
	> File Name: 216_获取姓名排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月18日 星期一 17时17分47秒
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
    string a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i][0] == 'M') a[i][0] = ' ';
        if(a[i][1] == 'r' || a[i][1] == 's') a[i][1] = ' ';
        if(a[i][2] == '.') a[i][2] = ' ';
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].length();j++){
            if(a[i][j] == ' ') continue;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
