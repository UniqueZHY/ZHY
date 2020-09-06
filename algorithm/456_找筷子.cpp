/*************************************************************************
	> File Name: 456_找筷子.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 15时00分55秒
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
    int n, t, cnt = 0;
    int a[1000000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(a[j] > a[j + 1]){
                t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cnt++;
        if(a[i] != a[i + 1]){
            if(cnt % 2 != 0){
                cout << a[i] << endl;
            }
            cnt = 0;
        }
    }
    return 0;
}
