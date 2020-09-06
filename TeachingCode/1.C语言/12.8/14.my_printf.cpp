/*************************************************************************
	> File Name: 14.my_printf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时45分56秒
 ***********************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int reverse_num(int num, int *temp) {//翻转
    int digit = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit += 1;//用来记录位数为了防止1000输出1；
    } while(num);
    return digit;
}

int output_num(int temp, int digit) {//讲翻转后的数字按位输出
    int cnt = 0;
    while (digit--) {
        putchar(temp % 10 + '0');
        temp /= 10;
        cnt += 1;//当前已经在屏幕上成功输出的个数
    }
    return cnt;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0) PUTC('-'), x = -xx;//如果为负数，就先输出负号
                        else x = xx;
                        int num1 = x / 100000, num2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(num1, &temp1);//翻转
                        int digit2 = reverse_num(num2, &temp2);//翻转
                        if (num1) digit2 = 5;
                        else digit1 = 0;
                        cnt += output_num(temp1, digit1);//用来记录打印出几个数
                        cnt += output_num(temp2, digit2);//用来记录打印出几个数
                    } break;
                    case '%': {
                        PUTC(frm[i]);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    va_end(arg);
    #undef PUTC
    return cnt;
}

int main() {
    int a = -123;
    printf("hello world\n");
    my_printf("hello world\n");
    printf("int (a) = %d\n", a);
    my_printf("int (a) = %d\n", a);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);
    char str[100] = "I love Beijing !";
    printf("%s\n", str);
    my_printf("%s\n", str);
    return 0;
}

