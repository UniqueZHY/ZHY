/*************************************************************************
	> File Name: 182_最大的数.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 20时17分30秒
 ************************************************************************/

#include<stdio.h>
int fun(int *a, int n) {
    int max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max)i; max = a[i];
    }
    return max;
}
int main(){
    int h[100];
    int n, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }
    ans = fun(h, n);
    printf("%d", ans);
    return 0;
}
/*int max (int a[],int n) {
        int max=a[0],i;
        for(i=0;i<n;i++)
                if(a[i]>max) max=a[i];
        return max;
}
int main() {
    int h[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }
    int ans = max(h, n);
    printf("%d", ans);
    return 0;

}*/
