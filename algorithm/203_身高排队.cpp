/*************************************************************************
	> File Name: 203_身高排队.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 11时30分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
struct height{
    int h;
}a[15][15];
/*bool cmp(height x, height y){
    return x.h > y.h;
}*/
bool cmp(int x, int y){
    return x > y;
}
int main(){
    int m, n, max = 0;
    double sum;
    cin >> m >> n;
    int tall[m * n + 5];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j].h;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[j][i].h > max){
                max = a[j][i].h;
            }
        }
        cout << max << endl;
        max = 0;
    }
    /*sort(a, a + n, cmp);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            j != 0 && cout << " ";
            cout << a[i][j].h;
            sum += a[i][j].h;
        }
    }*/
    int z = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tall[z] = a[i][j].h;
            z++;
        }
    }
    sort(tall, tall + (m * n), cmp);
    int cnt = 0, ans;
    double ave;
    for(int i = 0; i < m * n; i++){
        i != 0 && cout << " ";
        cout << tall[i];
        sum += tall[i];
    }
    cout << endl;
    ave = sum / (n * m);
    //cout << ave << endl;
    ans = ave;
    if(ave - ans >= 0.5) ans += 1;
    //cout << ans << endl;
    for(int i = 0; i < n * m; i++){
        if(tall[i] >= ans){
            cnt++;
        }
    }
    cout << ans << endl ;
    cout << cnt << endl;
    return 0;
}
