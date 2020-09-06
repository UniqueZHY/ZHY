/*************************************************************************
	> File Name: 176_寻找字符串.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月22日 星期五 22时53分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int main(){
    char str1[1005];
    char str2[1005];
    scanf("%[^\n]s", &str1);
    scanf("%s", &str2);
    char *find;
    int ans = 0;
    find = strstr(str1, str2);
    while(find != NULL){
        ans++;
        find = strstr(find + 1, str2);
    }
    cout << ans;
}
