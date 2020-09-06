/*************************************************************************
	> File Name: 219_交叉排序.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年11月26日 星期二 22时50分56秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
#define max_n 10000
int a[max_n + 5];
bool cmp1(int x, int y){
	return x < y;
}
bool cmp2(int x, int y){
	return x > y;
}
int main(){
	int n, l1,r1,l2,r2;
	cin >> n >> l1>> r1 >> l2 >> r2;
	for(int i  = 1; i <= n ;i++){
		cin >> a[i];
	}
	//sort(a + 1, a + n + 1);
	sort(a + l1, a + r1 + 1);
	sort(a + l2, a + r2 + 1, cmp2);
	for(int i = 1; i <= n; i++){
		i != 1 && cout << " ";
		cout << a[i];
	}
	return 0;
}
