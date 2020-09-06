/*************************************************************************
	> File Name: 13.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月20日 星期四 20时33分48秒
 ************************************************************************/
#include <stdio.h>
#define P(func, args...) {\
    printf("%s = %d\n", #func, func(args));\
}
// 1 3 5 7 9
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//11111111111110000000找最后一个1
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;//+1 避免死循环
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;//mid = 0不是1 所以可以-1
    }
    return head;
}

//0000000001111111111找第一个1
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;//不能 -1也许tail就是第一个
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}
int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int arr2[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search1, arr1, 10, 7);
    P(binary_search2, arr2, 10);
    P(binary_search3, arr3, 10);
    return 0;
}
