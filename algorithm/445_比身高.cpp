/*************************************************************************
	> File Name: 445_比身高.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月17日 星期日 23时43分19秒
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
    int n, q = 0, h = 0;
    int a[1005];
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        q = h = 0;
        for(int j = 0; j < i; j++){
            if(a[j] > a[i])
                q++;
        }
        for(int j = i + 1; j <= n; j++){
            if(a[j] > a[i])
                h++;
        }
        if(q == h){
            ans++;
        }
        //q = h = 0;
    }

    cout << ans << endl;
    return 0;
}
