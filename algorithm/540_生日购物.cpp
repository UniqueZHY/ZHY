/*************************************************************************
	> File Name: 540_生日购物.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 18时29分59秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;
//set01分别记录一半，cnt用来保存多少种方案，多少个sum
int n, cost, num[45], set[2][2100000], cnt[2]; 
//set 0 前一半set 1后一半，cnt计数器
void func(int set_num, int start, int end, int sum) {
    if (sum > cost) return ;
    for (int i = start; i < end; i++) {
        sum += num[i];
        set[set_num][cnt[set_num]] = sum;
        cnt[set_num]++;
        func(set_num, i + 1, end, sum);
        sum -= num[i];
    }
}

int main() {
    while (cin >> n >> cost) {
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        //分两部分
        func(0, 0, n / 2, 0);
        func(1, n / 2, n, 0);
        sort(set[1], set[1] + cnt[1]);
        int flag = 0;
        for (int i = 0; i < cnt[0]; i++) {
            int target = cost - set[0][i];
            int l = 0, r = cnt[1] - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (set[1][mid] == target) {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
                if (set[1][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 0) cout << "NO" << endl;
    }
    return 0;
}
