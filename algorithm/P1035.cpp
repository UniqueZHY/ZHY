/*************************************************************************
	> File Name: P1035.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月14日 星期六 15时08分17秒
 ************************************************************************/
#include<iostream>
using namespace std;
int main(){
    int i = 1, k;
    double sum = 0 ;
    cin >> k;
    while(1){
        sum = sum + 1.0 / i;
        i++;
        if(sum >= k){
            break;
        }
    }
    cout << i << endl;
    return 0;
}
