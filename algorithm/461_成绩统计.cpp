/*************************************************************************
	> File Name: 461_成绩统计.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 19时25分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct grade{
    string str;
    char flag;
    int n;
}stu[105];
int main(){
    int n, count = 0, sum = 0; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> stu[i].flag;
        if(stu[i].flag == 'C'){
            cin >> stu[i].str;
            count++;
        }
        if(stu[i].flag == 'N'){
            cin >> stu[i].n;
            sum += stu[i].n;
        }
    }
    cout << count  << " " << sum / (n - count) << endl;
    return 0;
}
