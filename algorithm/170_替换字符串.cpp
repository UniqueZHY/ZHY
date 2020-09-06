/*************************************************************************
	> File Name: 170_替换字符串.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 13时37分20秒
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
    int n;
    string a[100];
    string f;
    f = "Ban_smoking";
    string c;
    c = "No_smoking"; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans; 
    for(int i = 0; i < n ; i++){
        ans = a[i].find(f);
        if(ans != -1){
            a[i].replace(ans, c.length(), c);
            ans = a[i].find(f);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
