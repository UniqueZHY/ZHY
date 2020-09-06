/*************************************************************************
	> File Name: 70_丑数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 14时21分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int ugly_num(int x) {
    while(x % 2 == 0) {
        x /= 2; 
    }
    while(x % 5 == 0) {
        x /= 5;
    }
    while(x % 3 == 0) {
        x /= 3;
    }
    if(x == 1) return 1;
    else  return 0;
    
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(ugly_num(i) == 1){
            cout << i << endl;
        }
    }
    return 0;
}
