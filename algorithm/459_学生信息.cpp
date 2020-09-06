/*************************************************************************
	> File Name: 459_学生信息.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 23时47分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct person {
    char name[20000];
    char x;
    int age;
    float weight;
};
int main(){
    struct person zs;
    scanf("%s %c %d %f", zs.name, &zs.x, &zs.age, &zs.weight);
    printf("%s %c %d %.1f\n", zs.name, zs.x, zs.age, zs.weight);
    return 0;
}
