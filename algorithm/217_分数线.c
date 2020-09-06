/*************************************************************************
	> File Name: 217_分数线.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 15时20分50秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#define max_n 100000
int a[max_n + 5];
int main(){
    int n, m, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(n);
    m = n / 2;
    if(n % 2 != 0) m += 1;
    printf("%d ", a[m - 1]);
    ans = m;
    for(int i = m; i < n; i++){
        if(a[i] >= a[m - 1]){
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
