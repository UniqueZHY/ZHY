## 输入输出

[]字符匹配级 3.cpp

[\n] 不是换行就输入认为是字付

printf 

sprintf 字符数组中打印（可以控制输入格式）

~~~
sprintf(str2, "%d.%d.%d.%d", a, b, c, d);
printf("str2 = %s\n", str2);
~~~

~~~
输入 23 23 2134 453
输出 str2 = 23.23.2134.453
~~~

fprintf 打印到文件中

stdin    standard in 标准输入 在c语言中表现为调用scanf函数接受用户输入内容，即从终端设备输入内容。也可以用fscanf指明stdin接收内容。 标准输入的文件标识符为0。 

stdout standard out  在c语言中表现为调用printf函数将内容输出到终端上。使用fprintf也可以把内容输出到终端上。标准输出的文件标识符为1。

stderr  standard error 标准错误和标准输出一样都是输出到终端上， 标准错误输出的文件标识符为2。笔者更倾向于从语义上分析：在程序处理的时候，正常的信息输出作为标准输出，产生错误的输出作为标准错误输出。这样在重定向的时候，就可以将正常的信息和错误的信息重定向到不同的文件。

~~~
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    char str[100], str2[100];
    int ret;
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sprintf(str2, "%d.%d.%d.%d", a, b, c, d);
    FILE *fd = fopen("out", "wb");//write, b代表二进制，以二进制读入，更稳定
    fprintf(stdout, "stdout = %s\n", str2);//打印到stdout文件夹中
    fprintf(stderr, "stderr = %s\n", str2); 
    printf("str2 = %s\n", str2);
    return 0;
}
输入 12 13 14 15
输出 
stdout = 12.13.14.15
stderr = 12.13.14.15
str2 = 12.13.14.15
~~~

## C语言基本运算符

~~~
+, -, *, /, ()
&  2 & 3 转换成二进制
| 又叫做逻辑加法, 
^ 按位异或(逆运算,满足交换律。相同为0，不同为1) a ^ b = c --> c ^ b = a
~ 按位去反
~~~

~~~
<<, >> 左移右移 
7 << 1
7 = 000……0111(前面31-3个0)
7 << 1 = 00……1110(前面31-4个0)
4 / 2 == 4 >> 1		
~~~

## C语言中的数学函数

头文件:math.h

pow(a, n)求幂次 

> 返回值 double

sqrt(n) 求平方根 

> 返回值double

ceil(n) 向上取整

floor(n) 向下取整

abs(n) 

> (stdlib.h)求绝对值 n只能是int

fabs(n)

> (math.h) n是double

log(n)

log10(n)如果想算不同底数用换底公式

acos(n) 反三角函数 

> n 为弧度,弧度  = PI / 180

左值引用

>左值：对其操作后，后面能访问到，叫做左值

右值引用

>右值：对其操作后，不能访问。

优先级

结合方向  

~~~
    int a = 6, b = 3, d = 4;
    int *p = &a;
    *p--;//右结合，先--再取值
    printf("%d\n", a);
    输出 6
~~~

~~~
    int a = 6, b = 3, d = 4;
    int *p = &a;
    --*p;
    printf("%d\n", a);
	输出 5
~~~

-- 与 * 优先级相同，--从右向左。

# 入门组题答疑

C++包含了C语言的29个头文件

C++可以通过加C语言的头文件，用printf和scanfe

int 最大能存2^21

## C语言关系运算符2

== 

!=

<, >

!!(x) 归一化 !!5 = 1 

选择结构

```
1.if(表达式){
    代码段;
}

2.if(表达式){
    代码段1;
} else {
    代码段2;
}

3.if(表达式1){
    代码段1;
}else if(表达式2){
    代码段2;
}else{
    代码段3;
}
```

SWITCH语句

```
switch (a) {
    case 1: 代码块1; case为条件入口，程序进入case所对应的代码段，依次执行后续代码，知道遇到break或default。
    case 2: 代码块2;
    case 3: 代码块3;
}
```

while语句

```
while (表达式) {
    代码块;
}
do {
    代码块;
} while (表达式)
```

for语句

```
for (初始化;循环条件;执行后操作) {
    代码块;
}
```

```
    if ((a++) && (b++)){//此时,如果输入a=0,b = 0,(a++)等于1但是返回值为0，先赋值后加。故”&&“前为假不执行&&后面的语句
        cout << "true" << endl;
        cout << a << " " << b << endl;
    } else {
        cout << "false" << endl;
        cout << a  << " "<< b << endl;
    }
    //此时a = 1
    if ((a++) || (b++)){//此时(a++)返回值为1，为真，故"||"后面的语句不执行，a++ = 2
        cout << "true" << endl;
        cout << a << " " << b << endl;
    } else {
        cout << "false" << endl;
        cout << a << " " << b << endl;
    }
    cout << "a = " << a << "b = " << b << endl;

输入 0 0
输出
equal
false
true
a = 2 b = 0
…………………………………………………………………………………………………………………………………………………………………
短路原则
a=0;b=1
c=a&&(b=3)

最终c=0; b=1

因为从左至右进行时，若遇到运算符左边的操作数是 0（逻辑假），则停止运算。

a=1;b=1;c=0;

d=a||b||(c=b+3);

最终d=1;c=0;

因为从左至右进行时，若遇到运算符左边的操作数是 1（逻辑真），则停止运算。

记住！短路原则是 与（&&） 或（||） 才有。

x=1;y=1;c=0;

c=x++||y++;说明++的优先级高于||高于赋值运算符

printf("%d%d%d\n",x,y,c);

x=2;y=1;c=1v
…………………………………………………………………………………………………………………………………………………………………………
```

```
int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        if(val % 2 == 0) cnt += 1;
        i && cout << " ";
        cnt += !(val & 1);//a = (val & 1), if a== 1 则为奇数 0 为偶数
        i == 0 || cout << " ";
        cout << val;
    }
    cout << endl;
    cout << "odd number = " << cnt << endl;
```

```
计算一个数有几位---do while 与 while 的不同
int main() {
    int n;
    cin >> n;
    int digits = 0;
    /*while(n) {
        n /= 10;
        digits += 1;
    }
    cout << digits << endl;
    digits = 0;*/
    do {
        n /= 10;
        digits += 1;
    }while (n);
    cout << digits << endl;
    return 0;
}

```

# 习题答疑



回文整数

```
bool isPalindrome(int x) {
    if(__builtin_expect(!!(x), 1)){
        
    }
}
```

```
#define likely(x)  __builtin_expect(!!(x), 1) 经常能
#define unlikeli(x)  __builtin_expect(!!(x), 1)

```

- 尽量少的用if else
- (a && 1)奇数时为1
- 三目表达式

```
using namespace std;
int main() {
    double n;
    cin >> n;
    cout << n << endl;
    printf("%lf\n", n);//%g实数
    return 0;
}
输入 2.4
输出 2.4
2.4 
2.4
2.400000

```

```
某邮局托运包裹的运费标准是：包裹重量不大于 15 公斤时，每公斤 6 元；超过 15 公斤后，超过部分每公斤 9 元，给定包裹重量 X，计算邮费应为多少元。

using namespace std;
int main() {
    double x, y;
    cin >> x;
    y = (x > 15 ? 15 : x) * 6 + (x > 15) * (x - 15) * 9;
                                (x > 15)当x大于5时，表达式为1，
                                        小于5时，表达式为0,0乘以后面的就没了
    printf("%.2lf", y);
    return 0;
}
```



```
113. 一个月有多少天
#include<iostream>
using namespace std;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	int y, m, d;
	cin >> y >> m >> d;
	cout << (day[m] + (m == 2 && (y % 400 == 0 || y % 4 == 0 && y % 100 != 0))) << endl;
    return 0;
}
```

```
昨天今天和明天

int day[13] = {0,
    31,28,31,30,
    31,30,31,31,
    30,31,30,31
};
int Days(int y, int m){
    return Days[m] + (m == 2 && (y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0)));
}
void pre_day(int &y, int &&){
    d -= 1;urn day[m] + (m == 2&&(y % 4 == 0 && y % 100 != 0))
    if(d == 0) {
        m -= 1;
        if(m == 0) {
            y -= 1, m = 12;
        }
        d = Days(y, m);
    }
    return ;
}
void next_day(int &y, int &m , int &d) {
    d += 1;
    if(d > Days(y, m)) {
        m += 1, d = 1;
        if(m > 12) {
            y += 1, m = 1;
        }
    }
    return;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    prev_day(&y, &m, &d);
    cout << y << " " << m << " " << d << endl;
    next_day(y, m, d);
    next_day(y, m, d);
    cout << y << " " << m << " " << d << " " << endl;
    } 
```

- min(a, b)
- max(a, b)

```
131 N个数的极差
#include<iostream>
#include<cinttypes>
using namespace std;
int main(){
    int32_t n, a, ans_min = INT32_MAX, ans_max = INT32_MIN;//max定义成最大的,min定义成最小的
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ans_max = max(ans_max, a);
        ans_min = min(ans_min, a);
    }
    cout << ans_max - ans_min << endl;
    return 0;
}
```

```
134 十一的倍数
#include<iostream>
using namesapce std;
int main() {
int a, b;
cin >> a >> b;
for(int i = ((a - 1) / 11 + 1) * 11, j = 0; i <= b; i += 11, j++){
    j && cout << " ";
    cout << i;
}
    cout << endl;
    return 0;
}
```

```
122
#include<iostream>
#include<cstdio>
uisng namespace std;
char str[][10] = {"am", "pm", "midnoon"};
int main() {
    int t, h, s, m, f = 0;
    cin >> t;
    h = t / 3600;
    m = t % 3600 / 60;
    s = t % 60;
    if(h > 12) h -= 12, f = 1;
    printf("%02d:%02d:%02d", h, m, s);
    flag += 2 * (h == 12);
    printf("%s\n", str[f]);
    return 0;
}
```

```
引用 C++
void swap_t(int &a, int &b) {
    int temp = a;
    a = b; b = temp;
}
```

# 函数

特点：易读

返回值类型     函数名          参数声明列表

int                     is_prime     (   int     x    ) {

​	函数体;

​	return 

​         返回

}

## 递归程序：

递归程序：递归程序的组成部分

- 语义信息
- ！！！边界条件处理（确定递归出口）（处理不好容易爆栈）
- 针对于问题的处理过程和递归过程
- 结果返回

栈区 8mb约是200万整型 

 堆区 内存

递归时 回溯法

## 函数指针

用于类似分段函数的函数调用

int* a;指向int类型的指针变量

```
int g(int (*f1)(int), int (*f2)(int), int x) {
    
}
传入函数为参数，例传入fac函数，不是一定要写fac
```

```
传入函数为另一个函数的参数时。
#include<iostream>
using namespace std;
int fac1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * fac1(n - 1);
}

int fac2(int n) {
    return (1 + n) * n / 2;
}

int g(int (*func)(int), int (func2)(int), int x) {
    if (x < 5) return func(x);//x<5时调用参数中第一个的函数
    else return func2(x);//调用传入的参数的第二个函数
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("f(%d) = %d\n", n, g(fac1, fac2, n));
    }
    return 0;
}
```



```
欧拉35
#include<stdio.h>
#include<inttypes.h>
typedef int64_t int1;
int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}
int1 Hexagonal(int1 n) {
    return n * (2 * n - 1); 
}
int1 binary_search(int1 (*func)(int1), int1 x) {
    int1 head = 1, tail = x, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if(func(mid) < x) head = mid+1;
        else tail = mid - 1;
    }
    return -1;
}
int main() {
    int n = 286;
    for(;; n++) {
        if (binary_search(Hexagonal, Triangle(n)) == -1) continue;
        if (binary_search(Pentagonal, Triangle(n)) == -1) continue;
        printf("%" PRId64 "\n", Triangle(n));
        break;
    }
    return 0;
}
…………………………………………………………………………………………………………………………………………………………………………………………………………………………………………
/*#include<stdio.h>
int Triangle(int n) {
    return n * (n = 1) / 2;
}

int Pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}
int binary_search(int x) {
    int head = 1, tail = x, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (Pentagonal(mid) == x) return mid;
        if(Pentagonal(mid) < x) head = mid+1;
        else tail = mid - 1;
    }
    return -1;
}*/
```

## 变参函数

```
实现可变参数max_int从若干个传入的参数中返回最大值。
va一族
va_list 类型的变量 获得a往后的参数列表
va_start 函数 定位a后面第一个参数的位置
va_arg 函数  获取下一个可变参数列表中的参数
va_end 函数  结束整个获取可变参数列表的动作(⊙o⊙)…
#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h> 
//                 可变参数列表
int max_int(int n, ...) {//定参n表示后面变量数量
    va_list arg;//定义一个va_list指针来访问参数表
    va_start(arg, n);//初始化arg让它指向第一个变参，n之后的参数
    int ans = INT32_MIN;//int ans = 0;
    while (n--) {
        int temp = va_arg(arg, int);//或缺一个int型参数，并且arg指向下一个参数
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
```

```
#define swap_n(a, b) {\
	__typeof(a) __temp = a;\
	a = b, b = __temp;\
}
```

# 欧几里得算法

- 又名辗转相除法
- 迄今为止已知的最古老的算法
- 用于快速计算两个数字的最大公约数
- 还可以用于快速求解a * x + b * y = 1方程的一组整数解

```
#include<stdio.h>
int gcd (int a, int b) {
    //if (!b) return a;
    //return gcd(b, a % b);
    return (b ? gcd(b, a % b) : a);
}
int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}
```

# 扩展欧几里得算法

```
#include<stdio.h>
int ex_gcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    //*x = yy;//当前x等于上一次的y
    //*y = xx - a / b * yy;//当前的y等于上一次的x - a / b * y;
    *y -= a / b * (*x);//因为*x = 上一个y,*y = 上一个x-ky,y可被替换成*x, 而xx等于当前的*y.故整理为一行：*y -= a / b * (*x).
    return ret;
} 
int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}
```

![12.7扩展欧几里得](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/12.7%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97.jpg)

# 函数的声明和定义part 2

![TIM图片20191208174926](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174926.jpg)

![TIM图片20191208174930](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174930.jpg)

![TIM图片20191208174940](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174940.jpg)

![TIM图片20191208174944](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174944.jpg)

![TIM图片20191208174915](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174915.jpg)

![TIM图片20191208174922](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174922.jpg)

![TIM图片20191208174901](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174901.jpg)

![TIM图片20191208174906](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174906.jpg)

![TIM图片20191208174918](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174918.jpg)

![TIM图片20191208174910](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174910.jpg)

![TIM图片20191208174940](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174940.jpg)

![TIM图片20191208174944](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/TIM%E5%9B%BE%E7%89%8720191208174944.jpg)

- 函数声明写在头文件里
- 函数定义写在.c或.cpp文件里
- 头文件中的""引号代表在某路径下搜索当前的头文件或文件，从父目录搜索
- <>实在本身的库里 
- 可以多次声明，不可以多次定义

![深度截图_20191209111901](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_20191209111901.png)



![深度截图_20191209113025](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_20191209113025.png)

- funcA的定义应该写在funcA.cpp 或.c中

![深度截图_20191209112009](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_20191209112009.png)

- funcB的定义应该写在funcB.cpp 或.c中

![深度截图_20191209111922](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_20191209111922.png)

- funcA的声明应该写在funcA.h中



![深度截图_20191209111942](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_20191209111942.png)

- funcA的声明应该写在funcA.h中

```
实现简易printf
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
```

```
素数筛具体实现
#include<stdio.h>
#define max_n 1000

/*int prime[max_n + 5] = {0};

void init_prime() {
    prime[0] = 1, prime[1] = 1;
    for (int i = 2; i <= max_n; i++){
        if (prime[i]) continue;
        for (int j = i * i; j <= max_n; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}/*
//void init_prime() {}
int prime(int n) {
    if (n <= 1) return 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i) continue;
        return 1;
    }
    return 0;
}
int main() {
    //init_prime();
    int n;
    while(~scanf("%d", &n)) {
        printf("%s\n", prime(n) ? "no":"yes");//用函数
        //printf("%s\n", prime[n]?"no":"yes");//用数组
    }
    return 0;
}
```

