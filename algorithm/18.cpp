/*************************************************************************
	> File Name: 18.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 10时02分39秒
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
    int n ;
    cin >> n;
    int a[100000];
    for(int i = 0 ;i < n ;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] % 10 == 1 || a[i] % 10 == 4 || a[i] % 10 == 7){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        if(a[i] % 10 == 2 || a[i] % 10 == 5 || a[i] % 10 == 8){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        if(a[i] % 10 == 3 || a[i] % 10 == 6 || a[i] % 10 == 9){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
