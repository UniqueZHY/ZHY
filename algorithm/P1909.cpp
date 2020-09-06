/*************************************************************************
	> File Name: P1909.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月13日 星期五 15时24分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int n, i, g, m, b, a, min = 0x7fffffff;
    cin >> n;
    cout << min;
    for(i = 0; i < 3; i++){
        cin >> g >> m;
        a = n / g;
        if(n % g != 0){
            a = a + 1;
        }
        b = a * m ;
        if (b < min)
        min = b;
    }    
    cout << min << endl;
    return 0;
}
