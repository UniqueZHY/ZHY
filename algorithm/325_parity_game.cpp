/*************************************************************************
	> File Name: 325.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月26日 星期日 18时33分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define MAX_N 10000
int fa[MAX_N + 5],val[MAX_N + 5];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;
    }
    return ;
}

int get(int x) {
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 2;
    return fa[x] = root;//路径压缩
}

int merge (int x, int y, int t) {//0为偶数个1,1为奇数个1
    int a = get(x), b = get(y);
    if  (a == b) {//xy处于同一个集合
        return (val[x] - val[y] - t) % 2 == 0;
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 2) % 2;
    return 1;
}

map<int, int> ind;
int ind_cnt = 0;

struct Date {
    int x, y;
    string t;
}arr[MAX_N + 5];


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].t;
        arr[i].y += 1;
        ind[arr[i].x] = 0;
        ind[arr[i].y] = 0;
    }
    for (auto iter = ind.begin(); iter != ind.end(); iter++) {
        iter->second= (++ind_cnt);
        //iter->first
        //iter->second
    }
    init(ind_cnt);
    for (int i = 0; i < m; i++) {
        if (merge(ind[arr[i].x], ind[arr[i].y], arr[i].t[0] == 'o')) continue;
                                            //为odd奇数,arr[i].t[0]等于1，为偶数even,arr[0].t=0
        cout << i << endl;
        return 0;
    }
    cout << m << endl;
    return 0;
}
