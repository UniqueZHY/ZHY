/*************************************************************************
	> File Name: P2141.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年10月14日 星期一 20时01分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int i, j, k, m, n, l, sum = 0;
    int a[10001], q, z;
    cin >> l >> m;
    for(i = 0; i <= l; i++){
        a[i] = 0;
    }
    for(i = 1; i <= m; i++){
        cin >> q >> z;
        for(j = q; j <= z; j++){
            if(a[j] == 0){
                a[j]++;
            }
        }
    }
    for(i = 0; i <= l; i++){
        if(a[i] == 0){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
