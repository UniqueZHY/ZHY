/*************************************************************************
	> File Name: 477_元音字母.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月06日 星期五 21时35分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    char str[105];
    int arr[105];
    cin >> str;
    int len = strlen(str);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            arr[cnt++] = i;
        } else continue;
    }
    int maxx = 0;
    for (int i = 1; i < cnt; i++) {
        int temp = arr[i] - arr[i - 1];
        if (temp > maxx) maxx = temp;
        //cout << "i= " << i << "temp = " <<temp <<"maxx = " <<maxx << endl;
    }
    cout << maxx << endl;
    return 0;
}
