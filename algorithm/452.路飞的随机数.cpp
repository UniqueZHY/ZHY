/*************************************************************************
	> File Name: 452.路飞的随机数.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 11时31分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<cstdlib>
using namespace std;
int a[100];
void bubble_sort(int x){
    int t;
    for(int i = 1; i < x; i++){
        for(int j = 0; j < x - i; j++){
            if(a[j] > a[j + 1]){
                t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubble_sort(n);
    int cnt = unique(a, a + n) - a;
    cout << cnt << endl;
    for(int j = 0; j < cnt; j++){
        cout << a[j] << " ";
    }

    return 0;
}
