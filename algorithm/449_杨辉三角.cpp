/*************************************************************************
	> File Name: 449_杨辉三角.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 23时01分59秒
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
    int n, k = 1; 
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            if(j == 0 || j == i) cout << 1 << 
