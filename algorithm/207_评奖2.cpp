/*************************************************************************
	> File Name: 207_评奖2.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月21日 星期四 12时26分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int swapmax(int x, int y){
    return x > y ? x : y;

}
int swapmin(int x, int y){
    return x < y ? x : y;
}
struct score{
    char n[20];
    int m;
    int c;
    int e;
    int g;
    int all;
}a[35];
int main(){
    int n;
    int g[150];
    int d = 0;
    int x = 100;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].n >> a[i].m >> a[i].c >> a[i].e >> a[i].g;
        a[i].all = a[i].m + a[i].c + a[i].e + a[i].g;
      //  cin >> a[i].n;
      //  cin >> a[i].m;
        if(a[i].m > d)  d = a[i].m;
        if(a[i].m < x)  x = a[i].m;
      //  cin >> a[i].c;
        if(a[i].c > d)  d = a[i].c;
        if(a[i].c < x)  x = a[i].c;
        //cin >> a[i].e;
        if(a[i].e > d)  d = a[i].e;
        if(a[i].e < x)  x = a[i].e;
        //cin >> a[i].g;
        if(a[i].g > d)  d = a[i].g;
        if(a[i].g < x)  x = a[i].g;
    }
    int max = 0, k;
    for(int i = 0; i < n; i++){
        cout << a[i].all << endl;
    }
    for(int i = 0; i < n; i++){
        if(a[i].all > max){
            max = a[i].all;
            k = i;
        }
    }
    cout << a[k].n << endl;
    cout << d << " " << x;
    return 0;
}
/*struct score{
    string n;
    int all = 0;
}a[1000];
int main(){
    int n, sum = 0, score;
    int k = 0;
    int max = 0;
    int minn = 100;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].n;
        for(int j = 0; j < 4; j++){
            cin >> score;
            a[i].all += score;
            if(score > max) max = score;
            if(score < minn) minn = score;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i].all << endl;
        if(a[i].all > sum){
            sum = a[i].all;
            k = i;
        }
    }
    cout << a[k].n << endl;
    cout << max << " " << minn;
    return 0;
}*/
