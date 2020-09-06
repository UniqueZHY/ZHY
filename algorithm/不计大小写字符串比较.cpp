/*************************************************************************
	> File Name: T1114.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月10日 星期二 19时40分11秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
int main(){
    char a[80], b[80];
    int i, j;
    cin >> a;
    cin >> b;
    for(i = 0; i < strlen(a);i++){
        if(a[i] > 'A' && a[i] < 'Z'){
            a[i] += 32;
        }
    }
    for(i = 0; i < strlen(b); i++){
        if(b[i] > 'A' && b[i] < 'Z'){
            b[i] += 32;
        }
    }
    if(strlen(a) > strlen(b)){
        for(i = 0; i < lena;){
            if(b[i] == a[i]){
                i++;
            }
            if(b[i] > a[i]){
                cout << "<" << endl;
                break;
            }
            if(b[i] < a[i]){
                cout << ">" <<endl;
                break;
            }
        }
        if(i == strlen(a))
        cout << "=" << endl;
    }
    else{
        for(i = 0; i < strlen(a);){
            if(b[i] == a[i]){
                i++;
            }
            if(a[i] > b[i]){
                cout << ">" <<endl;
                break;
            }
            if(a[i] < b[i]){
                cout << "<" <<endl;
                break;
            }
        }
        if(i == strlen(b)){
            cout << "=" <<endl;
        }
    }
    return 0;
}
