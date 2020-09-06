/*************************************************************************
	> File Name: 197_排序的实现.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 23时47分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    int a[15];
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }
    sort(a, a + 10, cmp);
    for( int j = 0; j < 10; j++){
        j != 0 && cout << " "; 
        cout << a[j];
    }
    return 0;

}
