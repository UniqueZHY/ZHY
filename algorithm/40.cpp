/*************************************************************************
	> File Name: 40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 15时43分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//int keep[505] = {0, 0, 1, 1};
int step(int n) {
  //  if(keep[n]) return keep[n];
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;
    else return step(n - 2) + step(n - 3); 
}
int main() {
    int n;
    cin >> n;
    cout << step(n) << endl;
    return 0;
}
