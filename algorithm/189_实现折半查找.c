/*************************************************************************
	> File Name: 189_实现折半查找.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 19时41分35秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000005
int a[max_n];
int k[max_n];
int n;
int binary_search(int x){
    int l, r, mid;
    l = 1;
    r = n;
    while(l <= r){
        mid = (l + r) / 2;
        if(x == a[mid]) return mid;
        if(x > a[mid]) {
            l = mid + 1;
        }
        if(x < a[mid]){
            r = mid - 1;
        }
    }
    return 0;
}
int main(){
    int m, f = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n ; i++){
        scanf("%d", &a[i]);
    }    
    for(int j = 1; j <= m; j++){
        scanf("%d", &k[j]);
        if(f == 1) printf(" ");
        printf("%d", binary_search(k[j]));
        f = 1;
    }
    return 0;
}
