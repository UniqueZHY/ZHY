/*************************************************************************
	> File Name: 7.program_struct.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月03日 星期二 20时04分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
    srand(time(0));//随机种子，当前时间，秒，当前计算机所经历的时间戳，1900年1月1号
   // printf("%d\n", rand() % 100);
   // printf("%d\n", rand() % 100);
    //printf("%lu\n", time(0));
    int a, b;
    cin >> a >> b;
    /*if (a - b) {
        cout << "not equal" << endl;
    } else {
        cout << "equal" << endl;
    }*/

    if ((a++) && (b++)){//此时,如果a=0,(a++)等于1但是返回值为0，先赋值后加。
        cout << "true" << endl;
        cout << a << " " << b << endl;
    } else {
        cout << "false" << endl;
        cout << a  << " "<< b << endl;
    }
    //此时a = 1
    if ((a++) || (b++)){//此时a = 1, a++ = 2
        cout << "true" << endl;
        cout << a << " " << b << endl;
    } else {
        cout << "false" << endl;
        cout << a << " " << b << endl;
    }
    cout << "a = " << a << "b = " << b << endl;
    /*int cnt = 0;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        if(val % 2 == 0) cnt += 1;
        i && cout << " ";
        cnt += !(val & 1);
        i == 0 || cout << " ";
        cout << val;
    }
    cout << endl;
    cout << "odd number = " << cnt << endl;*/
    return 0;
}
