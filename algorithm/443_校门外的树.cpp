/*************************************************************************
	> File Name: 443_校门外的树.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 23时14分15秒
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
    int l, m;
    int x, y;
    int a[10005];// = {1};
    cin >> l >> m;
    for(int i = 0; i <= l; i++){
        a[i] = 1;
    }
    for(int i = 0; i < m;i++){
        cin >> x >> y;
        for(int j = x; j <= y; j++){
            if(a[j] == 1){
                a[j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= l; i++){
        if(a[i] == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
