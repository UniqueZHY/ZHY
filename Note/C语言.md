# C语言

## 第一节课

### 输入输出

[]字符匹配级 3.cpp

[\n] 不是换行就输入认为是字付

printf 

sprintf 字符数组中打印（可以控制输入格式）

```
sprintf(str2, "%d.%d.%d.%d", a, b, c, d);
printf("str2 = %s\n", str2);
```

```
输入 23 23 2134 453
输出 str2 = 23.23.2134.453
```

fprintf 打印到文件中

stdin    standard in 标准输入 在c语言中表现为调用scanf函数接受用户输入内容，即从终端设备输入内容。也可以用fscanf指明stdin接收内容。 标准输入的文件标识符为0。 

stdout standard out  在c语言中表现为调用printf函数将内容输出到终端上。使用fprintf也可以把内容输出到终端上。标准输出的文件标识符为1。

stderr  standard error 标准错误和标准输出一样都是输出到终端上， 标准错误输出的文件标识符为2。笔者更倾向于从语义上分析：在程序处理的时候，正常的信息输出作为标准输出，产生错误的输出作为标准错误输出。这样在重定向的时候，就可以将正常的信息和错误的信息重定向到不同的文件。

```
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
```

### C语言基本运算符

```
+, -, *, /, ()
&  2 & 3 转换成二进制
| 又叫做逻辑加法, 
^ 按位异或(逆运算,满足交换律。相同为0，不同为1) a ^ b = c --> c ^ b = a
~ 按位去反
```

```
<<, >> 左移右移 
7 << 1
7 = 000……0111(前面31-3个0)
7 << 1 = 00……1110(前面31-4个0)
4 / 2 == 4 >> 1		
```

###C语言中的数学函数

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

> 左值：对其操作后，后面能访问到，叫做左值

右值引用

> 右值：对其操作后，不能访问。

优先级

结合方向  

```
    int a = 6, b = 3, d = 4;
    int *p = &a;
    *p--;//右结合，先--再取值
    printf("%d\n", a);
    输出 6
```

```
    int a = 6, b = 3, d = 4;
    int *p = &a;
    --*p;
    printf("%d\n", a);
	输出 5
```

-- 与 * 优先级相同，--从右向左。

## 第二节课

### 入门组题答疑

C++包含了C语言的29个头文件

C++可以通过加C语言的头文件，用printf和scanfe

int 最大能存2^21

### C语言关系运算符2

== 

!=

<, >

!!(x) 归一化 !!5 = 1 

选择结构

~~~
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
~~~

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

~~~
for (初始化;循环条件;执行后操作) {
    代码块;
}
~~~

~~~
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
~~~

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

## 第三节课

### 习题答疑

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

## 第四节课

### 函数

特点：易读

返回值类型     函数名          参数声明列表

int                     is_prime     (   int     x    ) {

​	函数体;

​	return 

​         返回

}

### 递归程序：

+ 数学归纳法！！！

递归程序：递归程序的组成部分

- 语义信息
- ！！！边界条件处理（确定递归出口）（处理不好容易爆栈）相当于k0
- 针对于问题的处理过程和递归过程 相当于ki ->ki+1
- 结果返回 return
- sacnf("     %d          ",        &n      )
- ​              传入参数        传出参数
-   因其会改变scanf内部传出故为传入参数   

栈区 8mb约是200万整型 

 堆区 内存

递归时 回溯法

右移下取整，除号向0取整

-3/2=-1(上取整),3/2=1(下取整)

-3 >> 1 = -2(下取整)

### 函数指针

```
二维数组的函数指针不能写成
int arr[100][100];
int **p = arr;
而是
int arr【100】【100】；int（*p）【100】 = arr
因为arr + 1 不等于 p + 1
```

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

### 变参函数

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

### 欧几里得算法

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

### 扩展欧几里得算法

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

## 第五节课

### 函数的声明和定义part 2



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

## 第六节课

### 折半查找（二分查找）

~~~
#include<iostream>
using namespace std;
//递归
int binary_search(int *arr, int head, int tail, int x) {
    if (head > tail) return -1;
    int mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
    return binary_search(arr, head, tail, x);
    }
int main() {
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << binary_search(arr, 0, n - 1, x) << endl;
    return 0;
}

~~~

~~~
#include<iostream>
using namespace std;
int binary_search(int *a, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if(a[mid] == x) return mid;
        if(a[mid] < x) head = mid + 1;
        if(a[mid] > x) tail = mid - 1;
    }
    return -1;
}
int main() {
    int a[1000], n;
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << binary_search(a, n, x) << endl;
    return 0;
}
~~~

### 海贼密训

1 2 3 4 5 6 6 6 6 6 6 6 6 6 6 6 6 6找第一次出现的6的下标

0000001111111找到满足条件的第一个数

~~~
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//递归
/*int binary_search(int *arr, int head, int tail, int x) {
    if (head > tail) return -1;
    int mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    else if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
    return binary_search(arr, head, tail, x);
    }*/

/*0000000000011111111111111找第一个”1“比当前x大的第一个数
int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] > x) tail = mid;//不能减一，因为不知道当前mid是否为第一个
        else head = mid + 1;
    }
    return head == n ? -1 : head;
    //输入
    //2 4 5 6 8
    //6
    //输出 4
}*/

//111111110000000找最后一个“1”
//找当前x最小的
int binary_search2(int *arr, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;//为了防止4 5 4 5 4 5死循环
        if (arr[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    //cin >> x;
    //cout << binary_search1(arr, n - 1) << endl;
    cout << binary_search2(arr, n) << endl;
    return 0;
}
~~~

### 牛顿迭代

~~~
#include<iostream>
#include<stdio.h>
#include<math.h>
#define EPSL 1e-6
using namespace std;

double F(double x) {
    return x * x - 2;
}
double f(double x) {
    return 2 * x;
}

double NewTon(double (*F)(double), double (*f)(double)) {
    double x = 1.0;
    while (fabs(F(x)) > EPSL) {
        x -= F(x) / f(x); 
    }
    return x;
}

int main() {
    double x = NewTon(F, f);
    printf("%lf\n", x);
    printf("%lf * %lf - 2 = %lf\n", x, x, x * x - 2);
    return 0;
}
~~~

### 数组与地址

+ arr 和 arr + 1，代表向后移动一个元素的位置，当前arr类型占几个字节就是几个字节。就是指针地址加几，取决于类型int +4,char + 1

+ scanf为什么写"&",因为其作用是将个一数值传给当前变量，只能用传地址的方式，

+ 希望函数内部对当前参数进行值的修改时，叫做传出参数

+ 函数内部需要用的参数为传入参数

  ~~~
  int func(int *a) {//把整型变量看成只有一个元素的特殊数组
      *a = 123;
      *(a + 0) = 123;
      a[0] = 123;
  }
  这三个语句等价
  ~~~

  

+ sizeof(arr) = 400 sizeof(*a) 前者是整个数组所占字节，而后者是此指针变量所占字节

+ 不管是什么类型的指针变量，都是八个字节，变量是用来存值的，对于指针变量存的值为地址

+ 地址的长度喝什么有关系？操作系统

  ~~~
  
      printf("sizeof(*a) = %lu\n", sizeof(*a));
      printf("sizeof(arr) = %lu\n", sizeof(arr));
  ~~~

  ~~~
  int func_2(int n, int arr[n]){
      ...;
  }
  ~~~

  ### 传数组进函数

+ 一维数组

~~~
int func(int *a)
int func(int a[])
~~~

+ 二维数组
+ 无法直接用**a传，因为a[1] != arr[1]

~~~
int func_2((*a)[200])//传递 arr[100][200]a指向大小为200的数组变量
int func_2((*a)[200][300])//传递arr[100][200][300]只能省略一维，只能省略最高维，将其看成指针，如省略了，指针变量的行为模式和外面行为模式对不上，也就无法正确的索引值了
~~~

+ int *a , +1后跳一个int,也就是4字节
+ int ******a, +1后跳一个(int*), 也就是8字节
+ 

## 第七节课

### 预处理命令--宏定义

+ 以"#"开头的都叫做预处理命令
+ 宏定义
  + 井号define PI 3.1415926
  + 井号define MAX_N 10000
+ 定义傻瓜表达式
  + 井号define MAX_N(a, b) (a) > (b) ? (a) : (b) 
  + 井号define S(a, b) a * b
+ 定义代码段
  + 井号define P(a) {\ " \ "用来将两行代码链接到一起
  + printf ....\
  + }

![深度截图_选择区域_20191212181432](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212181432.png)

+ 非标准：不可转移的，换一台电脑就用不了了。

### 预处理命令--条件式编译

![深度截图_选择区域_20191212181828](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212181828.png)

+ if MAX_N 不是一个变量，是一个宏

### 预处理命令

.o结尾的是对象文件

.obj

链接是把所有的.o文件连接到一起，生成一个可执行程序，链接的是各种函数的

![深度截图_选择区域_20191212183029](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212183029.png)

~~~
 #include<stdio.h>
 #define MAX(a, b)({\
     __typeof(a) __a = (a);\
     //为了防止a++,或b++加两次，故用中间变量a若为int则typeof为int
     __typeof(b) __b = (b);\
     __a > __b ? __a : __b;\
 }) 
 #define P(func) {\
    printf("%s = %d\n", #func, func);\
    //"#"代表后面的展开的值转换成字符串，输出
}

 int main() {
    int a = 7;
    P(MAX(2 ,3));
    P(5 + MAX(2 ,3));    
    P(MAX(2, MAX(3 ,4)));
    P(MAX(2 ,3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
     return 0;
 }
~~~

![深度截图_选择区域_20191212191553](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212191553.png)

~~~
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
"#"字符串话
"##"连接到一起
~~~

+ 附加， define s(a, b) a * b 
+ define s(int , p) =>  int *p
+ 用()把代码段变为表达式

### 字符串

定义字符串数组：

char str[size];

初始化字符串数组：

char str[] = "hello world";

char str[size] = {'h', 'e', 'l', 'l', 'o'};

### 字符串相关操作

#### 头文件：string.h 

![深度截图_选择区域_20191212201948](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212201948.png)

+ strcpy(a, b) 将b拷贝到a中
+ strncpy(a, b) 安全的字符串拷贝，n代表最多拷贝n位
  + 两种情况 a < b 如果用strcpy ,会不够用
  + a > b ok
+ strcpy 三种情况
  + 大于零 , 说明str 1, str2
  + 小于零 , str1 < str2
  + 等于零, str1 == str2
+ memset (str, c, n) 传一个数组进来， 数值， 具体多少位，将一个数组具体赋值
  + memset(str, 0, sizeof(str)) 将每一位赋值为0（实际上是将他的每一个字节赋值）
  + memset (str, -1, sizeof(str)) 赋值成-1
  + memset (str, -1, sizeof(str)) 不是1，因为是按字节赋值
+ 只要第一个参数str是指针，数组类型无所谓

#### 头文件：stdio.h

![深度截图_选择区域_20191212202831](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191212202831.png)

~~~
用字符串相关操作方法，计算一个16进制表示的位数
sscanf 和 sprintf代码演示
 #include <stdio.h>
 #include <string.h>
 #include <inttypes.h>
 void test_sscanf() {
         char str1[] = "123 456 789 987";
         char str2[100];
         int a, b, c, d;
         sscanf(str1, "%d%[^$]s", &a, str1);//$一个字符串的末尾
         sscanf(str1, "%d%[^$]s", &b, str1);//%[^$]s 表示除了$都要
         sscanf(str1, "%d%[^$]s", &c, str1);
         sscanf(str1, "%d%[^$]s", &d, str1);
         int offset = 0;
         offset += sprintf(str2 + offset, "a = %d", a);
         offset += sprintf(str2 + offset, " b = %d", b);
         offset += sprintf(str2 + offset, " c = %d", c);
         offset += sprintf(str2 + offset, " d = %d", d);
         printf("%s\n", str2);
         printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
 }
 uint64_t strlen1(const char *str) {
         uint64_t i = 0;
         while (str[i]) i++;
         return i;
 }
 int strcmp1(const char *str1, const char *str2) {
         uint64_t i = 0;
     for (; str1[i] && str2[i]; i++) {
                 if (str1[i] - str2[i]) return str1[i] - str2[i];
     }
         return str1[i] - str2[i];
 }
 int main() {
    int n;
    char str[100] = "hello haizei";
     /*while (~scanf("%d", &n)) {
        sprintf(str, "%x", n);//%x以十六进制输出s
        printf("%s has %lu digit\n", str, strlen(str));
      }*/
    printf("%"PRIu64"\n", strlen1(str));
    printf("%"PRIu64"\n", strlen1("hello haizei"));
    return 0;
 }
~~~

####附加

```
将一个带有不定空格的字符串按空格分为几段
输入hello world
输出、
hello
world
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    char str[1000];
    scanf("%[^\n]", str);
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') str[i] = '\n';
    }
    printf("%s\n", str);
    return 0;
}


/*int main() {
    char str[1000];
    scanf("%[^\n]s", str);//hello world\0 12个
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') str[i] = '\0';//hello\0world\0
    }
    int pos = 0;
    while (pos < len) {
        pos += printf("%s", str + pos);//刚开始pos为0，后加上printf函数的返回值，即成功输出字符串个数，直到等于原字符串长度
        pos += 1;
        printf("\n");
    }
    return 0;
}*/

```
+ 宏附加

  ```
  #definie MAX(a, b)({\
      __typeof(a) __a = (a), __b = (b);\
      __a > __ b ? __a : __b;\
  })
  
  注：‘\’ 是为了使这些代码连接到一行，即这四行代码实则在操作系统眼中为一行
    与要加上一个‘（）’在外面，因为是将这些代码的最后的值给MAX所以把它用括号括起来，变成了一个表达式
  ```

  ![222222222](/home/unique/Desktop/海贼/picture/222222222.png)

## 第八节课

### 复杂结构与指针

~~~
       结构体名字  
struct person {
    char name[20];
    int age;
    char gender;
    float height;
};
~~~

访问方式：

+ struct node1 a;
+ ”.“直接访问(a.name)
+ “->”指针间接访问()

#### 共用体

~~~
union register {
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int number;
};
~~~

特点：

+ 当其中一部分改变其他也改变
+ 当中需要开辟空间中所需要的最大空间

随堂



#### 变量的地址

![深度截图_选择区域_20191214190427](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191214190427.png)

![深度截图_选择区域_20191214194201](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191214194201.png)













+ 指针变量也是变量
+ 指针变量占几个字节？(随堂1)
+ 64 8字节 
+ 32 4字节

~~~
int a;
int *p = &a;//定义时*是为了代表P是一个指针
*p = 5;//除了定义外的地方*p代表取值操作，*p等价于a,对*p的操作就是对a的操作.
~~~



#### 重点概念:__指针变量，也是变量__



#### 等价形式转换

![深度截图_选择区域_20191214195455](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191214195455.png)

_p + 1 相当于从p后移动一个元素，元素取决于指针类型，如果是整型变量的指针+1,跳4字节，double 跳8字节，char跳1字节_

p + 1 <=> &p[1] <=> &arr[1]

*(p + 1) <=> arr[1]

p->filed <=> (*p).filed <=>a.filed//p存a的地址

+ int a;
+ int *p = &a;
+ ->间接引用 通过指针访问字段

![深度截图_选择区域_20191214200239](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191214200239.png)

~~~
struct Data a[2], *p = a(此时可以认为p = a)
p[1].x
*(p + 1).x
(&a[1]) -> x
(a + 1) -> x
(p + 1) -> x
(&a[0] + 1) -> x

~~~

![7777777777](/home/unique/Desktop/海贼/picture/7777777777.png)

![深度截图_选择区域_20191214190520](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191214190520.png)

~~~
#include<stdio.h>

union IP {
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int is_little() {
    int x = 1;
    return ((char *)(&x))[0];//转换成字符串的首地址,在取地0位
}

int main() {
    printf("%d\n", is_little());
    union IP p;
    char str[20];
    int arr[4];
    while(~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2,arr + 3);
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        printf("%d\n", p.num);
    }
    return 0;
}
~~~

+ 附加
+ *p 

#### 函数指针

~~~
add相当于变量
int (*add)(int, int);//函数指针（int *add(int, int)//不知道是返回值为指针还是函数指针）
add相当于类型
typedef int (*add)(int, int);//函数指针类型
~~~

#### TYPEDEF用法:将变量变成类型（别名）

+ 内建类型的重命名：
  + typedef long long lint;
  + typedef char * pchar;

+ 结构体类型的重命名

  ​                      原类型

  + typedef struct __node{

  + int x;

  + }Node,      *PNode;

    原类型别名    指向结构体的指针类型的别名

  + 定义结构体时可直接写Node a;

  + *Pode表示指向

+ 函数指针命名：

  + typedef int (*func) (int);

#### 函数指针

+ 变量：int ( *add) (int ,int)
+ 函数指针：typedef int (*add) (int, int);

#### MAIN函数

~~~
int main ();
int main (int argc,    char *argv[]);
             参数个数     具体参数
int main (int argc,   char*argv[], char**env);
             参数个数   具体参数      环境变量
~~~
![深度截图_选择区域_20191215114313](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191215114313.png)

![深度截图_dde-desktop_20191214204508](/home/unique/Desktop/%E6%B5%B7%E8%B4%BC/picture/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_dde-desktop_20191214204508.png)

![深度截图_dde-desktop_20191214203605]()

![深度截图_dde-desktop_20191214203957](/home/unique/Desktop/海贼/picture/深度截图_dde-desktop_20191214203957.png)

#### typedef 和 define

~~~
#define pchar char *

typedef char *ppchar;
……………………………………………………………………………………………………………………………………………………     
     pchar p1, p2;
     ppchar p3, p4;
     printf("sizeof(p1) = %lu, sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
     printf("sizeof(p3) = %lu, sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
     
     输出
     sizeof(p1) = 8, sizeof(p2) = 1
     sizeof(p3) = 8, sizeof(p4) = 8
     p2和其他不一样，（g++ -E)
      char * p1, p2;//此时p2为char变量.
     ppchar p3, p4;

~~~

####附加

![55555555](/home/unique/Desktop/海贼/picture/55555555.png)

![66666](/home/unique/Desktop/海贼/picture/66666.png)

char a; short b; char c;double d;

一共占16

char1 short2 char 1

double 8

偏移量为0 2 3 8

例：

```
#include<iostream>
using namespace std;
#define offset(T, item) (long long)(&(((T *)(NULL))->item))

struct Data {
    short a;
    int b;
    double c;
    char d;
};

int main() {
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));    
    printf("%lld\n", offset(struct Data, c));
    printf("%lld\n", offset(struct Data, d));
    return 0;
}

```



![字节偏移量](/home/unique/Desktop/海贼/picture/字节偏移量.jpg)

# 欧拉计划

+ 对偶逻辑去缩进
+ 封装成函数

### 函数上界限

![深度截图_选择区域_20191216101416](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191216101416.png)

![深度截图_选择区域_20191216101400](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191216101400.png)

+ 就本题为例子
+ 每位上的数的五次幂相加等于原来的数
+ 如5一个位数最小为10000,故n位数的最小值则为10的n - 1次幂
+ 如5位数最大值为99999,9的5次幂乘以n，故n位数为9的5次幂乘以n
+ 画出如图曲线求得相交点即为上界

~~~
#include<stdio.h>
#include<inttypes.h>
#define max_n 200000

int prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i * i <= max_n; i++) {
        if (prime[i]) continue;
        //prime[++prime[0]] = i;<=>prime[0] += 1;prime[prime[0]] = i;
        for (int j = i * i; j <= max_n; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= max_n; i++) {
        !prime[i]&& (prime[++prime[0]] = i);
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
~~~

+ 素数筛是如何筛数的：
+ 是用每一个素数来筛合数

![深度截图_选择区域_20191217202230](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191217202230.png)

+ 线性筛是怎么筛数的：
+ 找每个数（包括合数）的最小素因子，将其乘以所有小于等于它素因子的素数，即为该数可筛出的数，首先从2开始2的最小素因子为2，所以可以筛去4……如果是6最小素因子为2所以只能筛12，而的最小素因子为其本身故可以筛出14，21，35等

~~~
线性筛代码（找到第10001个素数）欧拉7
#include<stdio.h>
#define max_n 200000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= max_n; j++) {
            if (prime[j] * i > max_n) break;
            prime[j * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}
int main() {
    init();
    
    printf("%d\n", prime[10001]);
    return 0;
}
~~~

#### 滑动窗口法

![深度截图_选择区域_20191219181127](/home/unique/Desktop/海贼/picture/深度截图_选择区域_20191219181127.png)

+ 加法不是减法的逆运算
+ 乘法不是除法的逆运算
+ 除法不是乘法的逆运算因为分母不能为0，如果不为0则可以逆运算 

输入重定向，从文件中读入 

+ vim input
+ ./a.out < input 

#### 方向数组

+ 方向数组里面存储了K个向量
+ N维
+ 每个向量呆鸟某个方向上的单位偏移量

### 项目

+ 注意程序执行顺序
+ ^代表非 "%[[^/n]]s"
+ scanf函数中， 输入流有指向指针
+ 右移相当于除2 左移相当于乘2
+ 左移，末尾补0 右移，头部补符号位
+ 负数等于正数的反码加1 ，补码表示法，可以将减法变成加法
+ -3除以2=-2（下取整，-1 > -2)
+ 负数一直右移最多-1不能变成0，正数可以变成0
+ C语言log函数以e为底
+ acos



求一个数的平方

右到左

<-------

！！(x) 先算里面(第二个)的再算外面的，x为真最后为1，x为假最后为0，归一化，将一个不确定的值变为1或0



++a++ => ++(a++) == 	1