/*************************************************************************
	> File Name: P1423.cpp
	> Author: zhanghongyanmZ
	> Created Time: 2019年09月14日 星期六 18时14分56秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int i;
    double x, n = 2, s = 2;
    cin >> x;
    for(i = 1; ;i++){
        n = n * 0.98;
        s = s + n; 
        if(s >= x){
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
