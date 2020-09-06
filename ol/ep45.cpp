/*************************************************************************
	> File Name: ep45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 19时55分07秒
 ************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

LL Triangle(LL n) { return n * (n + 1) >> 1; }
LL Pentagonal(LL n) { return n * (3 * n - 1) >> 1; }
LL Hexoagonal(LL n) { return n * (2 * n - 1); }

LL binary_search(LL (*num)(LL), LL n, LL x) {
    int head = 1, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return -1;
}

int main() {
    int n = 144;
    while (binary_search(Pentagonal, 2 * n, Hexoagonal(n)) == -1) {
        n++;
    }
    cout << Hexoagonal(n) << endl;
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long int1;
using namespace std;

int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}

int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*num)(int1), int1 n, int1 x) {
    int1 head = 1, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int1 n = 144;
    while (binary_search(Pentagonal,
        2 * n, Hexagonal(n)) == -1) n += 1;
    cout << Hexagonal(n) << endl;

    return 0;
}*/
