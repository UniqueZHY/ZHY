/*************************************************************************
	> File Name: 199_递推函数.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 18时20分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int a[10];
/*int f(int k, int b, int *a){
    if(k < 10) return k;
    else return a[0]*f(k-1, b, a) % b+a[1]*f(k-2, b, a) % b+a[2]*f(k-3, b, a)%b+a[3]*f(k-4, b, a)%b+a[4]*f(k-5, b, a)%b+a[5]*f(k-6, b, a)%b+a[6]*f(k-7, b, a);*/
int main(){
    int k, m;
    cin >> k >> m;
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }
    if(k < 10) cout << k << endl;
    else{
        
    }
    //cout << f(k, m, a) << endl;
    return 0;
}
