/*************************************************************************
	> File Name: 190_哥德巴赫猜想.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 20时45分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int a[10000000];

int main(){
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        a[i] = 1;
    }
    for(int i = 2; i * i <= n; i++){
        if(a[i]){
            for(int j = i * i; j <= n; j += i){
                a[j] = 0;
            }
        }
    }
    for(int i = 2; i <= n / 2; i++){
        if(a[i] == 1 && a[n - i] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
