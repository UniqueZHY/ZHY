/*************************************************************************
	> File Name: 198_斐波那契数列2.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 23时59分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
/*int f(int n){
    if(n == 1 || n == 2) return 1;
    else return f(n - 1) + f(n - 2);
}
int main(){
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}*/
int main(){
    int  n;
    cin >> n;
    int a[1000005];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    for(int i = 3; i <= n; i++){
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= 1000000007;
    }
    cout << a[n];
    return 0;
}
