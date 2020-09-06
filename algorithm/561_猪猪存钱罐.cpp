/*************************************************************************
	> File Name: 561_猪猪存钱罐.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时21分56秒
 ************************************************************************/
//只告诉了重量求最小价值，也就是说一种硬币可以无限使用,所以是完全背包问题
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int e , f, n, w[500], val[505], ans[10005];

int main(){
    memset(ans , 0x3F, sizeof(ans));
    ans[0] = 0;//不能从0开始初始化
    //求最小值如果ans数组为0那么最后输出的将会是全0，因为25行最开始是ans[1]和ans[0]比较取小的,所以除了0位置外的全部位置都设为最大值
    cin >> e >> f >> n;
    f -= e;
    for (int i = 1; i <=n ;i++) {
        cin >> val[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= f; j++) {
            ans[j] = min(ans[j] , ans[j - w[i]] + val[i]);
        }
    }
    if (ans[f] == 0x3F3F3F3F) {
        cout << "This is impossible." << endl;
    }else {
        cout << "The minimum amount of money in the piggy-bank is "  << ans[f] << ".\n";
    }
    return 0;
}
