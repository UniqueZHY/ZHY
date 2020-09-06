/*************************************************************************
	> File Name: jsk.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月06日 星期五 19时57分19秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char a[50];
    int i;
    while(cin >> a){
        for(i = 0; i < strlen(a) ;i++){
            if(a[i] >= 'a' && a[i] <= 'z'){
                a[i] = a[i] - 32;
                continue;
            }
            if(a[i] >= 'A' && a[i] <= 'Z'){
                a[i] = a[i] + 32;
                continue;
            }
        }        
        for(i = 0; i < strlen(a); i++){
            if(a[i] == 'x'){
                a[i] = 'a';
                continue;
            }
            if(a[i] == 'X'){
                a[i] = 'A';
                continue;
            }
            if(a[i] == 'y'){
                a[i] = 'b';
                continue;
            }
            if(a[i] == 'Y'){
                a[i] = 'B';
                continue;
            }
            if(a[i] == 'z'){
                a[i] = 'c';
                continue;
            }
            if(a[i] == 'Z'){
                a[i] = 'C';
                continue;
            }
            a[i] = a[i] + 3;
        }
        for(i = strlen(a); i >= 0; i--){
            cout << a[i];
        }
        cout << " " << endl;
    }
    return 0;
}
