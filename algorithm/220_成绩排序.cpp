/*************************************************************************
	> File Name: 220_成绩排序.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月19日 星期二 16时42分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct person{
    string n;
    int c;
    int m;
    int e;
    int s;
    int all;
};
struct person a[105];
int cmp1(person x, person y){
    if(x.c == y.c){
        return x.n < y.n;
    }
    else return x.c > y.c;
}
int cmp2(person x, person y){
    if(x.m == y.m){
        return x.n < y.n;
    }
    else  return x.m > y.m;
}
int cmp3(person x, person y){
    if(x.e == y.e){
        return x.n < y.n;
    }
    else return x.e > y.e;
}
int cmp4(person x, person y){
    if(x.s == y.s){
        return x.n < y.n;
    }
    else return x.s > y.s;
}
int cmp5(person x, person y){
    if(x.all == y.all){
        return x.n < y.n;
    }
    return x.all > y.all;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].n >> a[i].c >> a[i].m >> a[i].e >> a[i].s;
        a[i].all = a[i].c + a[i].m + a[i].e + a[i].s;
    }
    sort(a, a + n, cmp1);
    cout << a[0].n <<" " << a[1].n <<" "<< a[2].n <<" "<< a[3].n << endl;
    sort(a, a + n, cmp2);
    cout << a[0].n <<" " << a[1].n <<" "<< a[2].n <<" "<< a[3].n << endl;

    sort(a, a + n, cmp3);
    cout << a[0].n <<" " << a[1].n <<" "<< a[2].n <<" "<< a[3].n << endl;

    sort(a, a + n, cmp4);
    cout << a[0].n <<" " << a[1].n <<" "<< a[2].n <<" "<< a[3].n << endl;
      
    sort(a, a + n, cmp5);
    cout << a[0].n <<" " << a[1].n <<" "<< a[2].n <<" "<< a[3].n << endl;

    return 0;
}
