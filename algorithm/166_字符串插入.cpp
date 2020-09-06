/*************************************************************************
	> File Name: 166_字符串插入.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 11时50分03秒
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
    string s1;
    string s2;
    int n;
    cin >> s1 >> n >> s2;
    if(s1.length() > 100){
        cout << "100" << endl;
    }else{
        cout << s1.length() << endl;
    }
    s1.insert(n - 1, s2);
    cout << s1 << endl;
    int ans = 0;
    for(int i = s1.length() - 1; i >= 0; i--){
        if(s1[i] == 'x'){
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
