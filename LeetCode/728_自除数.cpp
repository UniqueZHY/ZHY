/*************************************************************************
	> File Name: 728_自除数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月02日 星期一 20时49分24秒
 ************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int solve(int x) {
    int a = x;
    while (a) {
        int b = a % 10;
        if (b == 0 || x % b != 0) return 0;
        a /= 10;
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 1000);
    int cnt = 0;
    for (int i = left; i <= right; i++) {
        if (solve(i)) {
            arr[cnt++] = i;
        }
        //arr[cnt++] = i;
    }
    *returnSize = cnt;
    return arr;
}
