/*************************************************************************
	> File Name: 593_魔法项链.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 20时15分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, ans[30005], mem[30005];
//mem数组存魔力值为x的字符串个数
char str[30005];
int main() {
    cin >> n >> m >> &str[1];
    for (int i = 1; i <= n / 2; i++) {//枚举长度
        int same = 0;
        for (int j = 1, k = i + 1; j <= i; j++, k++) {//起点为1的情况
            if (str[j] == str[k]) same++;
        }
        ans[same]++;
        for (int j = 2; j + 2 * i - 1 <= n; j++) {//枚举起点，开始一次比一个，公共部分已判断完
            if (str[j - 1] == str[j - 1 + i]) same--;
            //上一次和这一次比除去公共部分的数如果相同就说明魔法值中有1个是从它哪里来的，就要减下去，求得公共部分魔法值
            if (str[j + i - 1] == str[j + 2 * i - 1]) same++;
            //这一次新加进来的比除去公共部分的数如果相同就说明应该在原有魔法值基础上加1个
            ans[same]++;
        }
        mem[i] = same;
//因为后面还可能加新字符，为了方便可直接记录下原字符串最后一块的魔法值然后直接比较新进来的字符是否和对应位置上的字符相等就可以
    }
    for (int i = 0; i < m; i++) {//m次操作
        int t;
        cin >> t;
        if (t == 2) {
            cin >> t;//t=2是输出答案
            cout << ans[t] << endl;
            continue;
        }
        char l;
        cin >> l;//新加入一个字符
        str[++n] = l;
        if (n % 2 == 0) {
            int same = 0, mid = n / 2;
            //若加入后长度为偶数，则计算新长度子串
            //例原来字符串长度为7枚举最大长度为6，加一个变8个了就能枚举8个了
            for (int j = 1, k = 1 + mid; j <= mid; k++, j++) {
                if (str[j] == str[k]) same++;
            }
            ans[same]++;
            mem[mid] = same;
        }
        for (int j = 1; j <= (n - 1) / 2; j++) {
        //将之前所有长度最后状态取出，向后移动
            if (str[n - j - j] == str[n - j]) mem[j]--;
            if (str[n] == str[n - j]) mem[j]++;
            ans[mem[j]]++;
        }
    }
    return 0;
}
