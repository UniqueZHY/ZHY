/*************************************************************************
	> File Name: 58_完美的宏定义.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月26日 星期四 15时52分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX(a, b)({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
})

#define Plog(frm, arg...) {\
    printf("[ $%s : $%s ] %d", funcname, lineno, userdata);\
    printf(frm, ##arg);\
    printf("\n");\
};

void haizei_test() {
        int a = 6;
        Plog("%d", MAX(2, 3));
        Plog("%d", 5 + MAX(2, 3));
        Plog("%d", MAX(2, MAX(3, 4)));
        Plog("%d", MAX(2, 3 > 4 ? 3 : 4));
        Plog("%d", MAX(a++, 6));
        Plog("a value = %d", a);

}

int main() {
        haizei_test();
        return 0;

}
