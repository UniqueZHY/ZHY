/*************************************************************************
	> File Name: 177_字母图形.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 18时22分45秒
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
    char a[30];
    char b[30] = {0};
    cin >> a;
    cout << a << endl;
    int len = strlen(a);
    while(len){
        //cout << "d" << endl;
        b[0] = a[strlen(a) - 2];
        b[1] = a[strlen(a) - 1];
        for(int i = 0; i < strlen(a) - 2; i++){
            b[2 + i] = a[i];
        }
        cout << b << endl;
        strcpy(a, b);
        len--;
    }
    return 0;
}
