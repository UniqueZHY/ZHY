/*************************************************************************
	> File Name: 451_商品排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 00时02分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
//B
//void buble_sort()
int main(){
    int n, t;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++){
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
        cout << a[i] << endl;
    }
    return 0;
}
