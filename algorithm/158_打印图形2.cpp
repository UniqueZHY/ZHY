/*************************************************************************
	> File Name: 158_打印图形2.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 23时19分28秒
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
    int n;
    cin  >> n;
    int b = 2 * n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n + 1; j++){
            if(i == j){
                cout << n - i;
            }if (j == b - i){
                cout << n - i;
            }if((j < 2 * (n - i))){
                cout << " ";
            }
            //else cout << "a";
            }
        cout << endl;
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < 2 * n + 1; j++){
            if(i == 0 && j == n) cout << "0";
            else if(i > 0){
                if(j == n - i) cout << i;
                else if(j == i + n) cout << i;
                else cout << "a";
            }
            else cout << "a";
        }
        cout << endl;
    }
    return 0;
}
