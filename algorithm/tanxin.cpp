/*************************************************************************
	> File Name: tanxin.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年07月04日 星期四 17时03分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int v[6] = {1, 5, 10, 50, 100, 500};
    int c[6], a, i,ans = 0;
    for(i = 0; i <= 5 ;i++){
        cin >> c[i];
    }
    cin >> a ;
    for(i = 5;i >=0;i--){
        int t = min(a / v[i], c[i]);
        a = a - t * v[i];
        ans = ans + t;
    }
    cout << ans << endl;
    return 0;
}
