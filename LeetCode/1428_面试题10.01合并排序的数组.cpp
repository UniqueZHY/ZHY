/*************************************************************************
	> File Name: 1428_面试题10.01合并排序的数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 19时32分42秒
 ************************************************************************/

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int p = m - 1, q = n - 1, cnt = ASize - 1;
    while (p >= 0 && q >= 0) {
        if (A[p] < B[q]) A[cnt--] = B[q--];
        else A[cnt--] = A[p--];
    }
    if (p == -1) {
        for (int i = 0; i <= q; i++) {
            A[i] = B[i];
        }
    }
}
