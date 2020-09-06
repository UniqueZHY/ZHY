/*************************************************************************
	> File Name: 110_包裹托运.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月05日 星期四 19时08分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    double x, y;
    cin >> x;
    y = (x > 15 ? 15 : x) * 6 + (x > 15) * (x - 15) * 9;
    printf("%.2lf", y);
    return 0;
}
