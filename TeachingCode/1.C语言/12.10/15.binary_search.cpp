/*************************************************************************
	> File Name: 15.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月10日 星期二 18时55分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//递归
/*int binary_search(int *arr, int head, int tail, int x) {
    if (head > tail) return -1;
    int mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
    return binary_search(arr, head, tail, x);
    }*/

/*0000000000011111111111111找第一个”1“比当前x大的第一个数
int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] > x) tail = mid;//不能减一，因为不知道当前mid是否为第一个
        else head = mid + 1;
    }
    return head == n ? -1 : head;
    //输入
    //2 4 5 6 8
    //6
    //输出 4
}*/

//111111110000000找最后一个“1”
//找当前x最小的
int binary_search2(int *arr, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;//为了防止4 5 4 5 4 5死循环
        if (arr[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    //cin >> x;
    //cout << binary_search1(arr, n - 1) << endl;
    cout << binary_search2(arr, n) << endl;
    return 0;
}
