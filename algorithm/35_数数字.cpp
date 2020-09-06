/*************************************************************************
	> File Name: 35_数数字.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年11月26日 星期二 23时47分08秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
	int begin, end;
	cin >> begin >> end;
	if(begin < 0) begin = 0;
	if(begin <= end){
		for(int i = begin ; i <= end; i++){
			cout << i << endl;
		}
	}
	else cout << "ERROR" << endl;
	return 0;
}
