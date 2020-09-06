/*************************************************************************
	> File Name: 462_注册账号.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 20时13分35秒
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
    char flag;
    string str;
    long long num;
}per[10005];
int main(){
    int n, f = 0, m = 0, a = 0;
    long long ans, sum = 0;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        cin >> per[i].flag;
        if(per[i].flag == 'q'){
            cin >> per[i].num;
        }
        if(per[i].flag == 'i'){
            cin >> per[i].str;
        }   
        getchar();
    }
    for(int i = 0; i < n; i++){
        if(per[i].flag == 'q'){
            a++;
            sum += per[i].num;
        }
        else{
            if((per[i].str[per[i].str.length() - 2] - '0') % 2 == 0){
                //cout << i << "a" << endl;
                f++;
            }
            else{
                m++;
            }
        }
    }
    if(sum == 0){
        ans = 0;
    }
    else(ans = sum / a);
    cout << m << " " << f << " " << ans << endl;
    return 0;
}

