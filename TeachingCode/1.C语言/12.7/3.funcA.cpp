/*************************************************************************
	> File Name: 3.funcA.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时13分08秒
 ************************************************************************/
#include <stdio.h>//在本身的库里搜索
#include "2.funcB.h"//在“”路径下搜索文件
int funcA(int n) {
    printf("funcA : %d\n", n);
    if (n == 0) return 1;
    funcB(n - 1);
    return n;
}
