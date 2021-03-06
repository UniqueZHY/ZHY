/*************************************************************************
	> File Name: 194_两数之和.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 19时16分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int a[100005];
int binary_search(int k, int n){
    int l = 0;
    int r = n;
    int mid = (l + r) / 2;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] == k) return 1;
        else if(a[mid] > k) r = mid - 1;
        else if(a[mid] < k) l = mid + 1;
    }
    return -1;
}
int main(){
    int n, x, s, ans = 0;
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    cin >> s;
    for(int i = 0; i < n; i++){
        x = s - a[i];
        if(binary_search(x, n) == 1){
            ans = 1;
            break;
        }
    }
    if(ans == 1) cout << "YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}
