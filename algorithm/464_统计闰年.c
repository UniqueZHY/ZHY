/*************************************************************************
	> File Name: 464_统计闰年.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月11日 星期一 16时17分03秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int x, y, ans = 0;
    scanf("%d %d", &x, &y);
    for(int i = x; i <= y; i++){
        if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
            ans++;
            printf("%d是闰年\n", i);
        }
    }
    printf("%d", ans);

    return 0;
}
