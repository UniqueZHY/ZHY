/*************************************************************************
	> File Name: erfen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月10日 星期二 18时18分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int binary_search(int *a, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if(a[mid] == x) return mid;
        if(a[mid] < x) head = mid + 1;
        if(a[mid] > x) tail = mid - 1;
    }
    return -1;
}
int main() {
    int a[1000], n;
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << binary_search(a, n, x) << endl;
    return 0;
}
