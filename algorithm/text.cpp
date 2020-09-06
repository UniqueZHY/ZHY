/*************************************************************************
	> File Name: text.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 17时03分33秒
 ************************************************************************/

#include<iostream>
typedef unsigned long long ll;
using namespace std;
ll keep[1000] = {0};
ll step(int n) {

    //if(keep[n]) return keep[n];
    if(n < 0) return 0;
    if(n == 0) return 1; 
    if(!keep[n]){
        keep[n] = step(n - 2) + step(n - 3);
    }
    return keep[n];
}
int main() {
        int n;
        cin >> n;
        cout << step(n) << endl;
        return 0;

}
