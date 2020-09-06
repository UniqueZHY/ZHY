/*************************************************************************
	> File Name: P1980.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月19日 星期四 13时22分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int count = 0, i, x, a;
    long int n;
    cin >> n >> x;
    for(i = 1; i <= n; i++){
        a = i;
        while(a){
            if(a % 10 == x){
                count++;
            }
            a /= 10;
        }
    }
    cout << count << endl;
}
