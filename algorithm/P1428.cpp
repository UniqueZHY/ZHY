/*************************************************************************
	> File Name: P1428.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 16时18分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int i, j, n, f = 0;
    int a[100];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n; i++){
        f = 0;
        for(j = i - 1; j >= 0; j--){
            if(a[i] > a[j]){
                f++;
            }
        }    
        cout << f << " ";                   
    }
    return 0;
}
