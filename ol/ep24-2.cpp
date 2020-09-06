/*************************************************************************
	> File Name: ep24-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月28日 星期六 20时14分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int num[10];
    for (int i = 0; i < 10; i++)  num[i] = i;
    int k = 1000000 - 1;
    do {
        next_permutation(num, num + 10);
        k -= 1;
    } while (k);

    for (int i= 0; i < 10; i++){
        cout << num[i];
    }
    cout << endl;
    return 0;
}
