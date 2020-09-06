/*************************************************************************
	> File Name: P1046.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月22日 星期日 11时59分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a[10];
    int i, count = 0, hight;
    for(i = 0; i < 10; i++){
        cin >> a[i];
    }
    cin >> hight;
    for(i = 0; i < 10; i++){
        if(a[i] <= hight + 30){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
