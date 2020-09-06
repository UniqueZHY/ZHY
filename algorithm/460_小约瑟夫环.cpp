/*************************************************************************
	> File Name: 460.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月15日 星期五 20时21分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
/*using namespace std;
int main(){
    int a[1005];
    int n, k;
    cin >> n >> k;
    int number = n, count = 0;
    for(int i = 0; i < n ; i++){
        a[i] = i + 1;
    }
    while (number > 1){
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                continue;
            }
            count++;
            if(count == k){
                a[i] = 0;
                count = 0;
                number--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] != 0) cout << a[i];
    }
    return 0;
}*/
using namespace std;
typedef struct monkey{
    int num;
    int flag;
}monkey;
int main(){
    int n, k;
    cin >> n >> k;
    monkey mon[1005];
    int number = n;
    int count = 0;
    for(int i = 0; i < n; i++){
        mon[i].num = i + 1;
        mon[i].flag = 1;
    }
    while(number > 1){
        for(int i = 0; i < n; i++){
            if(mon[i].flag == 0) continue;
            count++;
            if(count == k){
                mon[i].flag = 0;
                count = 0;
                number--;
            }
        }
    }
    for(int j = 0; j < n; j++){
        if(mon[j].flag == 1){
            cout << mon[j].num;
        }
    }
    return 0;
}

