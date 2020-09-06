/*************************************************************************
	> File Name: 448_抽奖.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 15时36分48秒
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
    int a[105];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int num;
    cin >> num;
    for(int i = 0; i < n; i++){
        if(num == a[i]){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}
