/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 19时05分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n; 
    cin >> n;
    if(n == 0) cout << "FOOLISH" << endl;
    else if(n < 60) cout << "FALL" << endl;
    else if(n < 75) cout << "MEDIUM" << endl;
    else if(n <= 100) cout << "GOOD" << endl;
    return 0;
}
