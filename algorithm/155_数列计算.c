/*************************************************************************
	> File Name: 155_数列计算.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月06日 星期三 20时20分32秒
 ************************************************************************/

#include<stdio.h>
/*void num(int x, int *arr[10000]) {
    if(x == 1) return 3;
    int sum = 0;
    return num(x - 1, *arr[10000]);
    arr[1] = 3;
    for(int i = 2; i < x; i++) {
        arr[i] = arr[i - 1] + 2 * i;
    }
    for(int j = 0; j < x; j++){
        printf("%d", arr[j]);
        sum += arr[j];
    }
}*/
int main() {
    int n, sum;
    int a[10000];
    scanf("%d", &n);
    a[0] = 3;
    for(int i = 1; i < n; i++){
        a[i] = a[i - 1] + 2 * i;
    }
    for(int j = 0;j < n; j++){
        printf("%d\n", a[j]);
        sum += a[j];
    }
    printf("%d\n", sum);

    return 0;
}
