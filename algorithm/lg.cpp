/*************************************************************************
	> File Name: xia.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年05月08日 星期三 14时47分10秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int i;
    int a[10], b[10],c[10];
    int max = 8;
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    for(i = 1; i < 8; i++){
        cin >> a[i] >> b[i];
    }
    for(i = 1; i < 8; i++){
        c[i] = a[i] + b[i];
        if(c[i] >= max){
            max = c[i];
        }
    }
    for(i = 1; i < 8; i++){
        if(c[i] == max){
            break;
        }
    }
    cout << i << endl;
    return 0;
}
