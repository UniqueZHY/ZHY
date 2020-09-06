/*************************************************************************
	> File Name: 208_挑选队员.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 12时03分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int a[105];
/*bool cmp(int x, int y){
    return x > y;
}*/
int main(){
    int n, cnt = 1;
    int m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    //sort(a, a + n, cmp);
    sort(a, a + n, greater<int>());
    for(int i = 1; i < n; i++){
        while (a[i] == a[i - 1]){
            cnt++;
            i++;
        }
        if(cnt < m){
            cnt = 1;
        }else break;
    }
    cout << cnt << endl;
    return 0;
}
