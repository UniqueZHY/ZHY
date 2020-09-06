/*************************************************************************
	> File Name: 212_身高排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 23时24分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Stu {
    char name[10];
} arr[10];

int cmp(struct Stu a, struct Stu b) {
    int t = strcmp(a.name, b.name);
    return t < 0;
}

int main(){
    for (int i = 0; i < 10; i++) cin >> arr[i].name;
    sort(arr, arr + 10, cmp);
    for (int i = 0; i < 10; i++) {
        cout << arr[i].name << endl;
    }
    return 0;
}
