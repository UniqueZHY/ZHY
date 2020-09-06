/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月13日 星期五 00时00分49秒
 ************************************************************************/
#include<stdio.h>
#define DEBUG
#ifdef DEBUG
#define log(frm, arg...) {\
    printf("[%s : %s : %d]", __FILE__, __func__, __LINE__ );\
    printf(frm, ##arg);\
    printf("\n");\
};
#else
#define log(fre, arg...)
#endif//用来结束define DEBUG 和ifdef DEBUG
#define contact(a, b) a##b
//##代表连接 如果一个变量前面有他， 就停止展开

int main() {
    int a = 123;
    //A(B(a)); => B(a) + 3 => a * 2 + 3
    int abcdef = 15;
    //printf("[%s : %s : %d] %d\n", __FILE__, __func__, __LINE__, a);
    contact(abc, def) = 23;
        log("%d", a);
        log("hello world");
        log("%d", abcdef);
        return 0;
}
