/*************************************************************************
	> File Name: offset.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 18时21分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define offset(T, item) (long long)(&(((T *)(NULL))->item))

struct Data {
    short a;
    int b;
    double c;
    char d;
};

int main() {
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));    
    printf("%lld\n", offset(struct Data, c));
    printf("%lld\n", offset(struct Data, d));
    return 0;
}
