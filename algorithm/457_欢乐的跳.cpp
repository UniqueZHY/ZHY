/*************************************************************************
	> File Name: 457_欢乐的跳.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 15时39分42秒
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
    int n; 
    cin >> n;
    int a[1005];
    int b[1005]; 
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        b[i] = abs(a[i + 1] - a[i]);
    }
    /*for (int j = 0; j < n - 1; j++){
        cout << b[j] << endl;
    }*/
    sort(b, b + (n - 1));
    /*for(int j = 0 ;j < n - 1; j++){
        cout << b[j] << endl;
    }*/
    for(int i = 0; i < n - 1; i++){
        if(b[i] != i + 1){
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
}
