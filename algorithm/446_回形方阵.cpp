/*************************************************************************
	> File Name: 446_回形方阵.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 11时47分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int a[10][10];
    int n;
    int b = 1;
    cin >> n;
    for(int k = 0; k <= n / 2; k++){
        for(int i = k; i < n - k; i++){
            for(int j = k; j < n - k; j++){
                a[i][j] = b;
            }
        }
        b++;
    }    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            j != 0 && cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
}
