/*************************************************************************
	> File Name: 201_香克斯的随机数.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月23日 星期六 23时32分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<functional>
using namespace std;
int main(){
    int a[105];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, less<int>());
    int k = unique(a, a + n) - a;//返回尾地址 -a,返回个数
    //返回的是num去重后的尾地址，之所以说比不真正把重复的元素删除，其实是，该函数把重复的元素一到后面去了，然后依然保存到了原数组中，然后返回去重后最后一个元素的地址，因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序。
    cout << k << endl;
    for(int i = 0; i < k; i++){
        i != 0 && cout << " ";
        cout << a[i];
    }
    return 0;
}
