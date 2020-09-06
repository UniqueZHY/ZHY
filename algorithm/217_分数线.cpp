/*************************************************************************
	> File Name: 217_分数线.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 19时04分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define max_n 100000
int a[max_n + 5];
using namespace std;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    int n, m, ans;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for(int j = 0; j < n; j++){
        cout << a[j] << endl;
    }
    m = n / 2;
    if(n % 2 != 0) m += 1;
    printf("%d ", a[m - 1]);
    ans = m;
    for(int i = m; i < n; i++){
        if(a[i] >= a[m - 1]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
