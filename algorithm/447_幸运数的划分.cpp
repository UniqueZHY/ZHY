/*************************************************************************
	> File Name: 447_幸运数的划分.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月18日 星期一 00时25分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int luck(int a){
    while (a){
        if(a % 10 == 4||a % 10 == 7){
            a /= 10;
            continue;
        }
        return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++){
        if(luck(i) == 1 && n % i == 0){
            cout << "YES" << endl;
            return 0;
        }   
    }
    cout << "NO" <<endl;
    return 0;
}
