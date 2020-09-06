#STL

< <http://c.biancheng.net/view/343.html>

+ C++ 含义：Ｃ语言＋类＋模板

+ STL：standard template libary 

+ STL六大组件：容器，迭代器，算法，适配器，分配器，仿函数

  + 容器：系统帮我们封装好的数据结构

  + >数组　array, vector
    >
    >链表(单向链表，双向链表)　list/forward list lt
    >
    >栈 stack
    >
    >队列 deque
    >
    >树 map/set 
    >
    >hash表 hash_map

![stl](/home/unique/Desktop/海贼/picture/stl.png)

![stl2](/home/unique/Desktop/海贼/picture/stl2.png)

+ 容器用来存数据
+ 算法用来对数据进行操作
+ 迭代器用来对容器和算法之间进行链接的一个通道

STL被组织为下面的13个头文件：

<algorithm> <deque> <functional> <iterator> <vector> <list> <map> <memory> <numeric> <queue> <set> <stack> <utility>

一、算法主要由头文件<algorithm> <numeric> <funcational>组成

<algorithm> 是所有STL文件中最大的一个，它是由一大堆模板函数组成的，可以认为每个函数在很大程度上都是独立的其中常用到的功能范围涉及到比较，交换，查找，遍历操作，复制，修改，移除，反转，排序，合并等等。

<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数，包括加法和乘法在序列上的一些操作。

<funcational>中则定义了一些模板类，用以声明函数对象。 

二、容器

容器部分主要由头文件<vector> <list> <deque> <set> <map> <stack> <queue>组成。对于常用的一些容器和容器适配器（可以看作由其它容器实现的容器），可以通过下表总结一下它们和相应头文件的对应关系。

向量(vector) 连续存储的元素

列表(list) 由节点组成的双向链表，每个节点包含着一个元素<list>

双队列(deque) 连续存储的指向不同元素的指针所组成的数组<deque>

集合(set) 由节点组成的红黑树，每个节点都包含着一个元素，节点之间以某种作用于元素对的谓词排列，没有两个不同的元素能够拥有相同的次序<set>

​                                                                                                                                                                                                                                                                                   多重集合(multiset) 允许存在两个次序相等的集合<set>

栈(stack) 后进先出的值的排列<stack>

队列(queue) 先进先出的执的排列<queue>

优先队列(priority_queue) 元素的次序是由作用于所存储的值对上的某中谓词决定的一中队列<queue>

映射(map) 由{键，值}对组成的集合，一某种作用键对上的谓词排列<map>

多重映射(multimap) 允许键对有相等的次序的映射<map>

三、迭代器

迭代器部分主要由头文件<utility> <iterator>和<memory>组成。

<utility>是一个很小的头文件，它包括了贯穿使用在STL中的几个模板的声明，

<iterator>中提供了迭代器使用的许多方法，而对于<memory>的描述则十分的困难，它以不同寻常的方式为容器中的元素分配存储空间，同时也为某些算法执行期间产生的临时对象提供机制,<memory>中的主要部分是模板类allocator，它负责产生所有容器中的默认分配器.

##**vector相关函数**

1 基本操作

(1)头文件#include<vector>.

(2)创建vector对象，vector<int> vec;

(3)尾部插入数字：vec.push_back(a);

(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。

(5)使用迭代器访问元素.(6)插入元素：    vec.insert(vec.begin()+i,a);在第i个元素后面插入a;

(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素

　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

(8)向量大小:vec.size();

(9)清空:vec.clear()　　　//清空之后，vec.size()为０

```
<span style="font-size:18px;">#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
        int i=0;
        vector<int> vec;
        for(i=0; i<10; i++)
        {
                vec.push_back(i);　　　//10个元素依次进入，结果为10
        }
 
        for(unsigned int i=0; i<vec.size(); i++)
        {
        cout<<"初始化遍历："<<vec[i]<<endl;
        }
        //结果为：０，１，２，３，４，５，６，７，８，９
        vector<int>::iterator it;
 
        for(it = vec.begin(); it!=vec.end(); it++)
        {
        cout<<"迭代遍历："<<*it<<endl;
        }
　　//结果为：０，１，２，３，４，５，６，７，８，９
　　 vec.insert(vec.begin()+4,0);
　　//结果为:11
        for(unsigned int i=0; i<vec.size(); i++)
        {
        cout<<"插入遍历："<<vec[i]<<endl;
        }
        //结果为：０，１，２，３，０，４，５，６，７，８，９
        vec.erase(vec.begin()+2);
        for(unsigned int i=0; i<vec.size(); i++)
        {
        cout<<"擦除遍历："<<vec[i]<<endl;
        }
　　//结果为：０，１，３，０，４，５，６，７，８，９
        vec.erase(vec.begin()+3,vec.begin()+5);
　　
        for(vector<int>::iterator it = vec.begin(); it!=vec.end(); it++)
        {
        cout<<"迭代遍历："<<*it<<endl;
        }
        return 0;
}
```

###**数组转置 (<algorithm> reverse)**

```
reverse(v.begin(), v.end()) 直接将其转置
//排序前
    for (vector <int> :: iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    } 
    cout << endl;
    reverse(v.begin(), v.end());
    for (vector <int> :: iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    } 
    cout << endl;
运行结果
3 5 7 2 45 23 1 8 35 25 
25 35 8 1 23 45 2 7 5 3 
```

```
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (vector<int> :: iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    reverse(v.begin(), v.end());
    for (vector<int> ::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
运行结果
0 1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1 0
```

###**排序（<algorithm> sort）**

```
sort(v.begin(), v.end())
```

```
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    vector <int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(2);
    v.push_back(45);
    v.push_back(23);
    v.push_back(1);
    v.push_back(8);
    v.push_back(35);
    v.push_back(25);
    //排序前
    reverse(v.begin(), v.end());
    for (vector <int> :: iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    } 
    cout << endl;
    sort(v.begin(), v.end());//默认升序
    for (vector <int> ::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), cmp);
    for (vector <int> :: iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
运行结果
25 35 8 1 23 45 2 7 5 3 
1 2 3 5 7 8 23 25 35 45 
45 35 25 23 8 7 5 3 2 1 
```

## 迭代器

> <http://c.biancheng.net/view/338.html>

迭代器按照定义方式分成以下四种。 

1) 正向迭代器，定义方法如下：

```
容器类名::iterator  迭代器名;
```

2) 常量正向迭代器，定义方法如下：

```
容器类名::const_iterator  迭代器名;
```

3) 反向迭代器，定义方法如下：

```
容器类名::reverse_iterator  迭代器名;
```

4) 常量反向迭代器，定义方法如下：

```
容器类名::const_reverse_iterator  迭代器名;
```

迭代器都可以进行++操作。反向迭代器和正向迭代器的区别在于：

- 对正向迭代器进行`++`操作时，迭代器会指向容器中的后一个元素；
- 而对反向迭代器进行`++`操作时，迭代器会指向容器中的前一个元素。

### 迭代器的功能分类

不同容器的迭代器，其功能强弱有所不同。容器的迭代器的功能强弱，决定了该容器是否支持 STL 中的某种算法。例如，排序算法需要通过随机访问迭代器来访问容器中的元素，因此有的容器就不支持排序算法。

常用的迭代器按功能强弱分为输入、输出、正向、双向、随机访问五种，这里只介绍常用的三种。

1) 正向迭代器。假设 p 是一个正向迭代器，则 p 支持以下操作：++p，p++，*p。此外，两个正向迭代器可以互相赋值，还可以用==和!=运算符进行比较。

2) 双向迭代器。双向迭代器具有正向迭代器的全部功能。除此之外，若 p 是一个双向迭代器，则--p和p--都是有定义的。--p使得 p 朝和++p相反的方向移动

3) 随机访问迭代器。随机访问迭代器具有双向迭代器的全部功能。若 p 是一个随机访问迭代器，i 是一个整型变量或常量，则 p 还支持以下操作：

- p+=i：使得 p 往后移动 i 个元素。
- p-=i：使得 p 往前移动 i 个元素。
- p+i：返回 p 后面第 i 个元素的迭代器。
- p-i：返回 p 前面第 i 个元素的迭代器。
- p[i]：返回 p 后面第 i 个元素的引用。

list 容器的迭代器是双向迭代器。假设 v 和 i 的定义如下：

```
list<int> v;list<int>::const_iterator i;
```

则以下代码是合法的：

```
for(i=v.begin(); i!=v.end(); ++i) cout << *i;
```

以下代码则不合法：

```
for(i=v.begin(); i<v.end(); ++i) cout << *i;
```

因为双向迭代器不支持用“<”进行比较。以下代码也不合法：

```
for(int i=0; i<v.size(); ++i) cout << v[i];
```

因为 list 不支持随机访问迭代器的容器，也不支持用下标随机访问其元素。在 C++中，数组也是容器。数组的迭代器就是指针，而且是随机访问迭代器。例如，对于数组 int a[10]，int * 类型的指针就是其迭代器。则 a、a+1、a+2 都是 a 的迭代器。

### 迭代器的辅助函数

STL 中有用于操作迭代器的三个函数模板，它们是：

- advance(p, n)：使迭代器 p 向前或向后移动 n 个元素。
- dis[tan](http://c.biancheng.net/ref/tan.html)ce(p, q)：计算两个迭代器之间的距离，即迭代器 p 经过多少次 + + 操作后和迭代器 q 相等。如果调用时 p 已经指向 q 的后面，则这个函数会陷入死循环。
- iter_swap(p, q)：用于交换两个迭代器 p、q 指向的值。

 

要使用上述模板，需要包含头文件 algorithm。下面的程序演示了这三个函数模板的 用法。

```c++
#include <list>
#include <iostream>
#include <algorithm> //要使用操作迭代器的函数模板，需要包含此文件
using namespace std;
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    list <int> lst(a, a+5);
    list <int>::iterator p = lst.begin();
    advance(p, 2);  //p向后移动两个元素，指向3
    cout << "1)" << *p << endl;  //输出 1)3
    advance(p, -1);  //p向前移动一个元素，指向2
    cout << "2)" << *p << endl;  //输出 2)2
    list<int>::iterator q = lst.end();
    q--;  //q 指向 5
    cout << "3)" << distance(p, q) << endl;  //输出 3)3
    iter_swap(p, q); //交换 2 和 5
    cout << "4)";
    for (p = lst.begin(); p != lst.end(); ++p)
        cout << *p << " ";
    return 0;
}
```

程序的输出结果是：

1) 3

2) 2

3) 3

4) 1 5 3 4 2

## list

list 是顺序容器的一种。list 是一个双向链表。使用 list 需要包含头文件 list。双向链表的每个元素中都有一个[指针](http://c.biancheng.net/c/80/)指向后一个元素，也有一个指针指向前一个元素，如图1所示。  在 list 容器中，在已经定位到要增删元素的位置的情况下，增删元素能在常数时间内完成。如图2所示，在 ai 和 ai+1 之间插入一个元素，只需要修改 ai 和 ai+1 中的指针即可。__list 容器不支持根据下标随机存取元素__

![list](/home/unique/Desktop/海贼/picture/list.png)

list 的构造函数和许多成员函数的用法都与 vector 类似，此处不再列举。除了顺序容器都有的成员函数外，list 容器还独有如表 1 所示的成员函数（此表不包含全部成员函数，且有些函数的参数较为复杂，表中只列出函数名）。

![list2](/home/unique/Desktop/海贼/picture/list2.png)

```
用 list 解决约瑟夫问题。
约瑟夫问题是：有 n 只猴子，按顺时针方向围成一圈选大王（编号为 1~n），从第 1 号开始报数，一直数到 m，数到 m 的猴子退到圈外，剩下的猴子再接着从 1 开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王。编程求输入 n、m 后,输出最后猴王的编号。

输入数据：每行是用空格分开的两个整数，第一个是 n，第二个是 m（0<m, n<=1 000 000）。最后一行是：
0 0

输出要求：对于每行输入数据（最后一行除外），输出数据也是一行，即最后猴王的编号。

输入样例：
6 2
12 4
8 3
0 0
输出样例：
5
1
7
#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> monkeys;
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        monkeys.clear();  //清空list容器
        for (int i = 1; i <= n; ++i)  //将猴子的编号放入list
            monkeys.push_back(i);
        list<int>::iterator it = monkeys.begin();
        while (monkeys.size() > 1) { //只要还有不止一只猴子，就要找一只猴子让其出列
            for (int i = 1; i < m; ++i) { //报数
                ++it;
                if (it == monkeys.end())
                    it = monkeys.begin();
            }
            it = monkeys.erase(it); //删除元素后，迭代器失效，
                                    //要重新让迭代器指向被删元素的后面
            if (it == monkeys.end())
                it = monkeys.begin();
        }
        cout << monkeys.front() << endl; //front返回第一个元素的引用
    }
    return 0;
}
```

## deque

deque 也是顺序容器的一种，同时也是一个可变长数组。要使用 deque，需要包含头文件 deque。所有适用于 vector 的操作都适用于 deque。

deque 和 vector

 有很多类似的地方。在 deque 中，随机存取任何元素都能在常数时间内完成（但慢于vector）。它相比于 vector 的优点是，vector 在头部删除或添加元素的速度很慢，在尾部添加元素的性能较好，而 deque 在头尾增删元素都具有较好的性能（大多数情况下都能在常数时间内完成）。它有两种 vector 没有的成员函数：

void push_front (const T & val);  //将 val 插入容器的头部
void pop_front();  //删除容器头部的元素

## queue和priority_queue

### queue

queue 就是“队列”。队列是先进先出的，和排队类似。队头的访问和删除操作只能在队头进行，添加操作只能在队尾进行。不能访问队列中间的元素。

queue 可以用 list 和 deque 实现，默认情况下用 deque 实现。 

queue 的定义如下：

template < class T, class Cont = deque<T> >
class queue{
    ...
};

queue 同样也有和 stack 类似的 push、pop、top 函数。区别在于，queue 的 push 发生在队尾，pop 和 top 发生在队头。

### priority_queue

priority_queue 是“优先队列”。它和普通队列的区别在于，优先队列的队头元素总是最大的——即执行 pop 操作时，删除的总是最大的元素；执行 top 操作时，返回的是最大元素的引用。

priority_queue 可以用 vector 和 deque 实现，默认情况下用 vector 实现。 

priority_queue 默认的元素比较器是 less <T>。也就是说，在默认情况下，要放入 priority_queue 的元素必须是能用“<”运算符进行比较的，而且 priority _queue 保证以下条件总是成立：对于队头的元素 x 和任意非队头的元素 y，表达式“x<y”必为 false。

priority_queue 定义如下：

template < class T, class Container = vector <T>, class Compare = less<T> >
class priority_queue{
    ...
};

priority_queue 的第三个类型参数可以用来指定排序规则

和 set/multiset 不同，priority_queue 是使用“堆排序”技术实现的，其内部并非完全有序，但却能确保最大元素总在队头。因此，priority_queue 特别适用于“不停地在一堆元素中取走最大的元素”这种情况。priority_queue 插入和删除元素的复杂度都是 O(log(n))。虽然用 set/multiset 也能完成此项工作，但是 priority_queue 比它们略快一些。

priority_queue 队头的元素只能被查看或者修改，不能被删除。

priority_queue的用法示例如下。

```
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    priority_queue<double> pq1;
    pq1.push(3.2); pq1.push(9.8); pq1.push(9.8); pq1.push(5.4);
    while(!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    } //上面输出 9.8 9.8 5.4 3.2
    cout << endl;
    priority_queue<double,vector<double>,greater<double> > pq2;
    pq2.push(3.2); pq2.push(9.8); pq2.push(9.8); pq2.push(5.4);
    while(!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    //上面输出 3.2 5.4 9.8 9.8
    return 0;
}
程序的输出结果是：
9.8 9.8 5.4 3.2
3.2 5.4 9.8 9.8
```

## stack

stack 是容器适配器的一种。要使用 stack，必须包含头文件 <stack>。

stack就是“栈”。栈是一种后进先出的元素序列，访问和删除都只能对栈顶的元素（即最后一个被加入栈的元素）进行，并且元素也只能被添加到栈顶。栈内的元素不能访问。如果一定要访问栈内的元素，只能将其上方的元素全部从栈中删除，使之变成栈顶元素才可以

stack的定义如下：

template < class T, class Cont == deque <T> >
class stack{
    ...
};

第二个参数表明，在默认情况下，stack 就是用 deque 实现的。当然，也可以指定用 vector 或 list 实现。

虽然 stack 使用顺序容器实现，但它不提供顺序容器具有的成员函数。除了 size、 empty 这两个所有容器都有的成员函数外，stack 还有以下三个成员函数，如表 1 所示。

| 成员函数                 | 功  能                                                       |
| ------------------------ | ------------------------------------------------------------ |
| void pop();              | 弹出（即删除）栈顶元素                                       |
| T & top();               | 返回栈顶元素的引用。通过此函数可以读取栈顶元素的值，也可以修改栈顶元素 |
| void push (const T & x); | 将 x 压入栈顶                                                |

 

## 函数

find函数 __find(InIt first, InIt last, const T& val)__如果找到就返回该元素的迭代器，若找不到就返回last

##**字符串（<string>）**

### 输入

```
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
    string s1;
    s1 = "hello";

    string s2;
    char s[1024];
    //scanf 输入速度比cin快的多
    //scanf 是C函数，不可以输入string
    scanf("%s",s);
    s2 = s;
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
尾部添加字符字符串直接用+号 例如： s += 'a'; s += "abc",或者使用append方法，s.append（“123”）
```

### 删除

```
s.erase(it + 1,it + 4); clear（）
```

```
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    s = "0123456789";
    cout << s << endl;

    string :: iterator it = s.begin();
    //删除s[3]
    s.erase(it + 3);
    cout << s << endl;
    
    //删除s[1] ~ s[3]
    s = "0123456789";
    s.erase(it + 1, it + 4);
    cout << s << endl;

    //全部删除
    s.clear();
    cout << "clear :" << s << endl;
    return 0;
}
运行结果
0123456789
012456789
0456789
clear :

```

###sscanf与sprintf

```
sscanf() - 从一个字符串中读进与指定格式相符的数据. 
　　函数原型: 
　　Int sscanf( string str, string fmt, mixed var1, mixed var2 ... ); 
　　int scanf( const char *format [,argument]... ); 
　　说明： 
　　sscanf与scanf类似，都是用于输入的，只是后者以屏幕(stdin)为输入源，前者以固定字符串为输入源。 
　　其中的format可以是一个或多个 {%[*] [width] [{h | l | I64 | L}]type | ' ' | '\t' | '\n' | 非%符号} 
　　注： 
　　1、 * 亦可用于格式中, (即 %*d 和 %*s) 加了星号 (*) 表示跳过此数据不读入. (也就是不把此数据读入参数中) 
　　2、{a|b|c}表示a,b,c中选一，[d],表示可以有d也可以没有d。 
　　3、width表示读取宽度。 
　　4、{h | l | I64 | L}:参数的size,通常h表示单字节size，I表示2字节 size,L表示4字节size(double例外),l64表示8字节size。 
　　5、type :这就很多了，就是%s,%d之类。 
　　6、特别的：%*[width] [{h | l | I64 | L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值 
　　支持集合操作： 
　　%[a-z] 表示匹配a到z中任意字符，贪婪性(尽可能多的匹配) 
　　%[aB'] 匹配a、B、'中一员，贪婪性 
　　%[^a] 匹配非a的任意字符，贪婪性 


例子： 
　　1. 常见用法。 
　　char buf[512] = ; 
　　sscanf("123456 ", "%s", buf); 
　　printf("%s\n", buf); 
　　结果为：123456 
　　2. 取指定长度的字符串。如在下例中，取最大长度为4字节的字符串。 
　　sscanf("123456 ", "%4s", buf); 
　　printf("%s\n", buf); 
　　结果为：1234 
　　3. 取到指定字符为止的字符串。如在下例中，取遇到空格为止字符串。 
　　sscanf("123456 abcdedf", "%[^ ]", buf); 
　　printf("%s\n", buf); 
　　结果为：123456 
　　4. 取仅包含指定字符集的字符串。如在下例中，取仅包含1到9和小写字母的字符串。 
　　sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf); 
　　printf("%s\n", buf); 
　　结果为：123456abcdedf 
　　5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。 
　　sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf); 
　　printf("%s\n", buf); 
　　结果为：123456abcdedf 
　　6、给定一个字符串iios/12DDWDFF@122，获取 / 和 @ 之间的字符串，先将 "iios/"过滤掉，再将非'@'的一串内容送到buf中 
　　sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf); 
　　printf("%s\n", buf); 
　　结果为：12DDWDFF 
　　7、给定一个字符串““hello, world”，仅保留world。（注意：“，”之后有一空格） 
　　sscanf(“hello, world”, "%*s%s", buf); 
　　printf("%s\n", buf); 
　　结果为：world 
　　%*s表示第一个匹配到的%s被过滤掉，即hello被过滤了 
　　如果没有空格则结果为NULL。 
　　sscanf的功能很类似于正则表达式, 但却没有正则表达式强大,所以如果对于比较复杂的字符串处理,建议使用正则表达式. 
　
```

```
　sprintf
　　由于sprintf 跟printf 在用法上几乎一样，只是打印的目的地不同而已，前者打印到字符串中，后者则直接在命令行上输出。
如：
//把整数123 打印成一个字符串保存在s 中。
sprintf(s, "%d", 123); //产生"123"
可以指定宽度，不足的左边补空格：
sprintf(s, "%8d%8d", 123, 4567); //产生：" 123 4567"
当然也可以左对齐：
sprintf(s, "%-8d%8d", 123, 4567); //产生："123 4567"
也可以按照16 进制打印：
sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
sprintf(s, "%-8X", 4568); //大写16 进制，宽度占8 个位置，左对齐
```



```
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
    string s1,s2,s3;
    char sa[100],sb[100],sc[100];
    sscanf("abc 123 wcd","%s%s%s",sa,sb,sc);
    s1 = sa;
    s2 = sb;
    s3 = sc;
    cout << s1 << " " << s2 << " " << s3 << endl;

    //将字符串分离成数字，分隔符为',''$'
    int a,b,c;
    sscanf("4,5$6","%d,%d$%d",&a,&b,&c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}
输出
abc 123 wcd
4 5 6 
```

#####string与char 

```
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
    string s_string;
    char s_char[1000];
    scanf("%s",s_char);

    s_string = s_char;

    //printf输出char* 时用c_str处理
    printf(s_string.c_str());
    cout << endl;

    printf("%s",s_char);
    cout << endl;

    cout << s_char << endl;
    cout << s_string << endl;
    return 0;
}
```

###　**string与数值相互转换( sprintf <sstream> )**

 ```
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

//c++ 方法 把数转换为string
string converToString(double x)
{
    ostringstream o;
    if( o << x)
    {
        // str()没有'\0' c_str有
        return o.str();
    }
    return "error";
}

double converFromString(const string &s)
{
    istringstream i(s);
    double x;
    if( i >> x)
    {
        return x;
    }
    //if error
    return 0.0;
}
int main() {
    char b[100];
    string s1;

    //c语言方法
    sprintf(b,"%d",1987);
    s1 = b;
    cout << s1 << endl;

    string s2 = converToString(1954);
    cout << s2 << endl;

    string s3 = "202";
    int c = converFromString(s3);
    cout << c << endl;

    string s4 = "casacsa6";
    int d = converFromString(s4);
    cout << d << endl;

    string s5 = "21abf4";
    int f = converFromString(s5);
    cout << f << endl;

    return 0;
}
 ```

##栈

```
empty() 堆栈为空则返回真

pop() 移除栈顶元素 （删除）

push() 在栈顶增加元素 （增加）

size() 返回栈中元素数目

top() 返回栈顶元素，不删除（获取）
栈有两种实现结构，一种是顺序存储结构，也就是利用数组实现，一种是链式存储结构，可以用单链表实现。数组实现栈很简单，用一个下标标记top来表示栈顶，top==-1时，栈空，top==0时，表示栈里只有一个元素，通过访问top为下标的数组元素即可。出栈top自减，入栈top自加就OK了。
```

##队列

```
back() 返回最后一个元素
empty() 如果队列空则返回真
front() 返回第一个元素
pop() 删除第一个元素
push() 在末尾加入一个元素
queue 的基本操作举例如下：
queue入队，如例：q.push(x); 将x 接到队列的！！！末端！！！。
queue出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
访问queue队首元素，如例：q.front()，即最早被压入队列的元素。
访问queue队尾元素，如例：q.back()，即最后被压入队列的元素。
判断queue队列空，如例：q.empty()，当队列空时，返回true。
```

优先队普通的队列是一种先进先出的数据结构，元素在队列尾追加，而从队列头删除。

在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征

**首先要包含头文件#include<queue>**, 他和`queue`不同的就在于我们可以自定义其中数据的优先级, 让优先级高的排在队列前面,优先出队。

优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。

> 和队列基本操作相同:
>
> - top 访问队头元素
> - empty 队列是否为空
> - size 返回队列内元素个数
> - push 插入元素到队尾 (并排序)
> - emplace 原地构造一个元素并插入队列
> - pop 弹出队头元素
> - swap 交换内容

__定义：priority_queue<Type, Container, Functional>__
Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式。

当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆。
一般是

```
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
```

# 位运算

& 与

| 或

！非 

^ 异或  不进位加法 相同0 不同1

补码

__按位与运算符(&)__

定义：参加运算的两个数据，按二进制位进行“与”运算。

运算规则：

```
0&0=0  0&1=0  1&0=0  1&1=1
```

总结：两位同时为**1**，结果才为**1**，否则结果为**0**。

例如：`3&5` 即 0000 0011& 0000 0101 = 0000 0001，因此 3&5 的值得1。

注意：负数按**补码**形式参加按位与运算。

与运算的用途：

**1）清零**

如果想将一个单元清零，即使其全部二进制位为0，只要与一个各位都为零的数值相与，结果为零。

**2）取一个数的指定位**

比如取数 X=1010 1110 的低4位，只需要另找一个数Y，令Y的低4位为1，其余位为0，即Y=0000 1111，然后将X与Y进行按位与运算（X&Y=0000 1110）即可得到X的指定位。

**3）判断奇偶**

只要根据最未位是0还是1来决定，为0就是偶数，为1就是奇数。因此可以用`if ((a & 1) == 0)`代替`if (a % 2 == 0)`来判断a是不是偶数。

__按位或运算符（|）__

定义：参加运算的两个对象，按二进制位进行“或”运算。

运算规则：

```
0|0=0  0|1=1  1|0=1  1|1=1
```

总结：参加运算的两个对象只要有一个为1，其值为1。

例如：`3|5`即 0000 0011| 0000 0101 = 0000 0111，因此，`3|5`的值得7。　

注意：负数按**补码**形式参加按位或运算。

或运算的用途：

**1）常用来对一个数据的某些位设置为1**

比如将数 X=1010 1110 的低4位设置为1，只需要另找一个数Y，令Y的低4位为1，其余位为0，即Y=0000 1111，然后将X与Y进行按位或运算（X|Y=1010 1111）即可得到。

__异或运算符（^）__

定义：参加运算的两个数据，按二进制位进行“异或”运算。

运算规则：

```
0^0=0  0^1=1  1^0=1  1^1=0
```

总结：参加运算的两个对象，如果两个相应位相同为0，相异为1。

异或的几条性质:

1、交换律

2、结合律 (a^b)^c == a^(b^c)

3、对于任何数x，都有 x^x=0，x^0=x

4、自反性: a^b^b=a^0=a;

异或运算的用途：

**1）翻转指定位**

比如将数 X=1010 1110 的低4位进行翻转，只需要另找一个数Y，令Y的低4位为1，其余位为0，即Y=0000 1111，然后将X与Y进行异或运算（X^Y=1010 0001）即可得到。

**2）与0相异或值不变**

例如：1010 1110 ^ 0000 0000 = 1010 1110

**3）交换两个数**

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
void Swap(int &a, int &b){
    if (a != b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
```

__取反运算符 (~)__

定义：参加运算的一个数据，按二进制进行“取反”运算。
运算规则：　

```
~1=0
~0=1
```

总结：对一个二进制数按位取反，即将0变1，1变0。

异或运算的用途：

**1）使一个数的最低位为零**

使a的最低位为0，可以表示为：`a & ~1`。~1的值为 1111 1111 1111 1110，再按"与"运算，最低位一定为0。因为“ ~”运算符的优先级比算术运算符、关系运算符、逻辑运算符和其他运算符都高。

__左移运算符(<<)__

定义：将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。

设 a=1010 1110，`a = a<< 2` 将a的二进制位左移2位、右补0，即得a=1011 1000。

若左移时舍弃的高位不包含1，则每左移一位，相当于该数乘以2。

__右移运算符(>>)__

定义：将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。

例如：a=a>>2 将a的二进制位右移2位，左补0 或者 左补1得看被移数是正还是负。

操作数每右移一位，相当于该数除以2。

## 位运算实现加法

```c
int add (int x, int y) {
    int n1 = x & y;
    int n2 = x ^ y;
    while (n1) {
        int tx = n2;
        int ty = n1 << 1;
        n1 = tx & ty;
        n2 = tx ^ ty;
    }
    return n2;
}
```

## 位运算实现乘法

```
add (~x, y)
```

## 位运算实现乘法

![img](https://img-blog.csdn.net/20171016102000011?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvWVBKTUZD/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

```
(1) 判断乘数是否为0，为0跳转至步骤(4)
(2) 将乘数与1作与运算，确定末尾位为1还是为0，如果为1，则相加数为当前被乘数；如果为0，则相加数为0；将相加数加到最终结果中；
(3) 被乘数左移一位，乘数右移一位；回到步骤(1)
(4) 确定符号位，输出结果；
```

```
int multiply(int a, int b) {　　
    //将乘数和被乘数都取绝对值　
    int multiplicand = a < 0 ? add(~a, 1) : a; //被乘数　　
    int multiplier = b < 0 ? add(~b , 1) : b;　//乘数
    　
    //计算绝对值的乘积　　
    int product = 0;　　
    while(multiplier > 0) {　　　　
        if((multiplier & 0x1) > 0) {// 每次考察乘数的最后一位　　　　
            product = add(product, multiplicand);　　　　
        } 　　　　
        multiplicand = multiplicand << 1;// 每运算一次，被乘数要左移一位　　　　
        multiplier = multiplier >> 1;// 每运算一次，乘数要右移一位（可对照上图理解）　　
    } 　　
    //计算乘积的符号　　
    if((a ^ b) < 0) {　　　　
        product = add(~product, 1);　　
    } 　　
    return product;
}
```

## 位运算实现除法

先让除数b被除数a对齐 ，判断b是否小于a, 小于就减去，然后得到的结果当下一轮的被除数a

​				如果b 大于 ，就将b右移一位，再用被除数a减去移位后的b，减后结果作为下一轮被除数a

```

```

