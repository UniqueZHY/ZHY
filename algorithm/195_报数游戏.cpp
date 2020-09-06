/*************************************************************************
	> File Name: 195_报数游戏.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 23时54分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#define max_n 100005
using namespace std;
typedef long long ll;
ll a[max_n];
int binary_search(ll n, ll x){
    ll l, r, mid;
    l = 0;
    r = n - 1;
    mid = (l + r) >> 1;
    while(l <= r){
        mid = (l + r) >> 1;
        if(a[mid] == x){
            return a[mid];
        }else if(a[mid] > x){
            r = mid - 1;
        }else if(a[mid] < x){
            l = mid + 1;
        }
    }
    return (a[0] > x ? a[0] : a[r]);
}
int main(){
    int n, m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll find;
    for(ll j = 0; j < m; j++){
        cin >> find;
        cout << binary_search(n, find) << (j < m - 1 ? " " : "");
    }
    return 0;
}
