/*************************************************************************
	> File Name: 167_字符串插入2.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 13时11分26秒
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
    string a;
    string b;
    string c;
    int n;
    cin >> a >> n >> b;
    cout << a.length() << endl;
    c = a;
    a.insert(n - 1, b);
    int ans = 0;
    for(int i = 0; i < c.length(); i++){
        if(c[i] == 'a'){
            ans = i + 1;
            break;
        }
    }
    cout << ans  << endl;
    cout << a << endl;
    return 0;
}
