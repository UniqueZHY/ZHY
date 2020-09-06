/*************************************************************************
	> File Name: 150_矩阵旋转.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 19时46分22秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[200][200];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = n - 1; j >= 0; j--){
            j != n - 1 && printf(" ");
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
