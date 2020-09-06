/*************************************************************************
	> File Name: ep34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 20时10分54秒
 ************************************************************************/
#include <stdio.h>
#define max_n 2540160
int num[10];
void init(int *num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;    
    }
        return ;
}

int is_val(int x) {
    int tmp = x, sum = 0;
    while (x) {
        sum += num[x % 10];
        x /= 10;
            
    }
        return sum == tmp;
}

int main() {
    int sum = 0;
    init(num);
    for (int i = 3; i < max_n; i++) {
        if (is_val(i)) sum += i;    
    }
    printf("%d\n", sum);
    return 0;
}

