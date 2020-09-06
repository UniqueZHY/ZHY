/*************************************************************************
	> File Name: 588_数列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时35分20秒
 ************************************************************************/

#include <iostream>
using namespace std;

int ans[31][10005] = {{}, {1}}, n;
//第0行为空第一行为1

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int ind = 0;
        for (int j = 0; ans[i - 1][j] != 0; j++) {
            //根据上一行算当前行
            int x = 1;//x用来记录有几个相同的 
            while (ans[i - 1][j] == ans[i - 1][j + 1]) {//当上一行两个数相同时
                x++;//例3个1 x就=3，j就=1
                j++;
            }
            ans[i][ind++] = x;//所以当前行就应该是3 1
            ans[i][ind++] = ans[i - 1][j];
        }
    }
    for (int i = 0; ans[n][i] != 0; i++) {
        cout << ans[n][i];
    }
    cout << endl;
    return 0;
}
