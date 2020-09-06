/*************************************************************************
	> File Name: 2.funcB.h
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时10分24秒
 ************************************************************************/

#ifndef _2.FUNCB_H//
#define _2.FUNCB_H

int funcB(int n) {
    printf("funcB: %d\n", n);
    if (n == 0) return 1;
    return n * funcB(n - 1);
}
#endif
