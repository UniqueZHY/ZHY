/*************************************************************************
	> File Name: 192_方程求解.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 20时12分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
double binary_search(double a){
    double l = 0;
    double r = 30;
    double mid;
    while(r - l > 1e-6){
        mid = (l + r) / 2.0;
        //if(exp(mid) * mid == a) return mid;
        if(exp(mid) * mid > a) r = mid;
        if(exp(mid) * mid < a) l = mid;
    }
    return mid;
}
int main(){
    double a;
    cin >> a;
    double ans;
    ans = binary_search(a);
    cout << fixed << setprecision(4) << ans << endl;
    
    return 0;
}
