/*************************************************************************
	> File Name: 200_数列计算.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月20日 星期三 19时44分26秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    float b[35];
    cin >> n;
    float a[35];
    a[1] = 4;
    a[2] = 7;
    b[1] = a[1] / a[2];
    double sum;
    for(int i = 3; i <= n + 1; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << "/" << a[n + 1] << endl;
    for(int i = 1; i < n + 1; i++){
        b[i] = a[i] / a[i + 1];
        //cout << b[i] << endl;
        sum += b[i];
    }
    printf("%.2f", sum);
    return 0;
}
