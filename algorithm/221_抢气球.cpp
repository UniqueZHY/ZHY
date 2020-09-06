/*************************************************************************
	> File Name: 221_抢气球.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 20时23分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct child{
    int h;
    int num;
}a[100005];
bool cmp(child x, child y){
    return x.h < y.h;
}
int q[100005];
int ans[100005] = {0};
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].h;
        a[i].num = i;
    }
    for(int j = 1; j <= m; j++){
        cin >> q[j];
    }
    sort(a + 1, a + n + 1, cmp);
    sort(q + 1, q + m + 1);
    int p = 1;
    for(int i = 1; i <= n ;i++){
        while(p <= m && a[i].h >= q[p]){
            ans[a[i].num]++;
            p++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
