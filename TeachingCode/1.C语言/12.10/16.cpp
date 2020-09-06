/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月10日 星期二 20时32分02秒
 ************************************************************************/

#include<stdio.h>
//指针变量才可以接受地址
/*int func(int *n) {//n为形式参数
    *n = 123;
    return 0;
}*/
int func(int *a, int n) {
    *a = 123;
    *(a + 0)
    a[0] = 123;
    printf("*a = %lu\n", sizeof(a));
    //printf("func : a[3] =  %d\n", a[3]);
    return 0;
}

//*(arr + 0)
//arr[0]
//*(arr + i)取arr[i]

int main() {
    int arr[100];
    printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p, arr + 2 = % p\n", arr+1, arr+2);
    char *p = (char *)arr;
    printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
    int n = 0;
    scanf("%d", &n);
    //scanf("%d", &n);
    //func(&n);//n为形式参数
   // printf("%d\n", n);
    /*for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }*/
    func(arr, n);
    printf("arr = %lu", sizeof(arr));
    return 0;
}





int func(int *a) {
    *a = 1213;
    *(a + 0) = 123;
    a[0] = 123;
}
