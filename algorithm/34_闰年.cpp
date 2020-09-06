/*************************************************************************
	> File Name: 34_闰年.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 00时31分14秒
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
    int y;
    cin >> y;
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        cout << "L" << endl;
    }
    else cout << "N" << endl;
    return 0;
}
