/*************************************************************************
	> File Name: max_int.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 16时26分39秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h> 
//                 可变参数列表
int max_int(int n, ............) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;//int ans = 0;
    while (n--) {
        int temp = va_arg(arg, int);//宏
        temp > ans && (ans = temp);
    }
    va_end(arg);//销毁arg的变量
    return ans;
}
int main() {
    printf("%d\n", max_int(3, 3, 5, 16));
    printf("%d\n", max_int(3, 3, 5, 16, 21));
    printf("%d\n", max_int(4, 3, 5, 21, -32));
    return 0;
}
