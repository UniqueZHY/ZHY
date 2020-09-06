/*************************************************************************
	> File Name: P1089.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月12日 星期四 18时27分07秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int m, c, b, i;
    for(i = 1; i <= 12; i++){
        cin >> c;
        m = m + 300;
        m = m - c;
        if(m < 0){
            cout << -i <<endl;
            exit(0);
        }
        if(m > 100){
            b += m / 100;
            m = m % 100;
        }
    }
    b = b * 100 + b * 100 * 0.2;
    cout << b << endl;
    return 0;
}   
