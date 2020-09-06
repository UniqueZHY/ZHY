/*************************************************************************
	> File Name: 215_评奖1.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月18日 星期一 11时52分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct per{
    char name[10];
    int  score[5];
    int  all = 0;
};
struct per a[45];
int cmp(per a, per b){
    return a.all > b.all;
}
int main(){
    //struct per a[45];
    int n;
    int g[5];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].name;
        for(int j = 0; j < 4; j++){
            cin >> a[i].score[j];
            a[i].all += a[i].score[j];
        }
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < 3; i++){
        cout << a[i].name << endl;
    }
    return 0;
}
