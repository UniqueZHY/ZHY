/*************************************************************************
	> File Name: 141_输出字母沙漏.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 19时04分43秒
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
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            cout << "A";
        }
    }

    return 0;
}
