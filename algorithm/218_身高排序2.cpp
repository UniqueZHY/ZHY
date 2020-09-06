/*************************************************************************
	> File Name: 218_身高排序2.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 19时58分58秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct Node{
    int hight, num;
};
bool cmp(struct Node a, struct Node b){
    if(a.hight == b.hight) return a.num < b.num;
    return a.hight < b.hight;
}
int main(){
    int n;
    cin >> n;
    struct Node a[100005];
    for (int i = 0; i < n; i++){
        cin >> a[i].hight;
        a[i].num = i + 1;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++){
        cout << a[i].num << (i < n - 1 ? " " : "");
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
typedef long long ll;
using namespace std;
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;\
}
struct Node{
    int height, num;
};
bool cmp(struct Node a, struct Node b) {
    if (a.height == b.height) return a.num < b.num;
    return a.height < b.height;
}
int main() {
    int n, m;
    struct Node a[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        Node temp = {m, i + 1};
        a[i] = temp;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].num << (i < n - 1 ? " " : "");
    }
    return 0;
}*/
