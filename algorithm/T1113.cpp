/*************************************************************************
	> File Name: T1113.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月07日 星期六 16时20分30秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char a[20];
    int n, i;
    cin >> n;
    while(n--){
        cin >> a;
        for(i = 0; i < strlen(a); i++){
            if(i == 0){
                if(a[i] >= 'a' && a[i] <= 'z'){
                    a[i] = a[i] - 32;
                }
            }
            else{
                if(a[i] >= 'A' && a[i] <= 'Z'){
                    a[i] = a[i] + 32;
                }
            }
        }
        for(i = 0; i < strlen(a); i++){
            cout << a[i] ;
        }  
        cout << endl;
    }
    return 0;
}
