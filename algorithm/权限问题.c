/*************************************************************************
	> File Name: rwx.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月03日 星期日 11时00分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int get_num(char *a) {
    int sum = 0, i = 0;
    while (a[i] != 0) {
        if (a[i] == 'r') {
            sum += 4;
        } else if (a[i] == 'w') {
            sum += 2;
        } else {
            sum += 1;
        }
        i++;
    }
    return sum;
}
int main() {
  int r = 4, w = 2, x = 1;
    int ans = 0, temp = 0;
    char a[20] = {0};
    while (scanf ("%[^ \n]s",  a) != EOF) {
        getchar();
      if (a[0] == '+') {
            temp = temp | get_num(a + 1);
        } else if (a[0] == '-') {
            temp = temp & (~get_num(a + 1));
        } else {
            temp  = temp | get_num(a);
        }
    }
    printf("%d\n", temp);
    return 0;
}
