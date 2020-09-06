/*************************************************************************
	> File Name: 39_输出一定数量的偶数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 19时29分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int begin, n, ans;
    cin >> begin >> n;
    if(begin < 0) begin = 0;
    if(begin % 2 != 0) begin++;
    ans = begin;
    for(int i = 0; i < n; i++){
        cout << ans << endl;
        ans += 2;
    }
    return 0;
}
