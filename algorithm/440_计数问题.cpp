/*************************************************************************
	> File Name: 440_计数问题.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 15时42分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int func(int a, int x){
    int sum, ans = 0;
    while(a){
        sum = a % 10;
        if(sum == x){
            ans++;
        }
        a /= 10;
    }
    return ans;
}
int main(){
    int n, x, ans = 0;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        ans += func(i, x);
    }
    cout << ans << endl;
    return 0;
}
