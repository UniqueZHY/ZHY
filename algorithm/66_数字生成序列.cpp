/*************************************************************************
	> File Name: 66_数字生成序列.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年11月26日 星期二 23时57分34秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
/*int func(int n){
	int t = 2;
	if(n == 1) return t;
	if(n % 2 == 0) {
		t += 1;
		return func(n / 2);
	}
	if( n % 2 != 0) {
		t += 1;
		return func(3 * n + 1);
	}
}*/
int main(){
	int n, t = 1;
	int max = 0;
	for(int i = 2; i <= 1000000; i++){
		n = i;
		//t = 1;
		while(n > 1){
			t = 1;
			if(n % 2 == 0){
				n = n / 2;
				t++;
			}
			else{
			n = 3 * n + 1;
				t++;
			}
		}
		if(t > max){
			int temp;
			temp = max;
			max = t;
			t = temp;
		}
	}
	cout << t;
	return 0;
}
