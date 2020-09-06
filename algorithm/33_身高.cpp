/*************************************************************************
	> File Name: 33_身高.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 00时24分30秒
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
int main(){
    double m , n, p, ans;
    cin >> m >> n >> p;
    if(p == 0){
        ans = (m * 0.973 + n) / 2.0;
    }else{
        ans = ((m + n) * 1.087) / 2.0;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
