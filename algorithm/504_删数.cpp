/*************************************************************************
	> File Name: 504_删数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 19时15分22秒
 ************************************************************************/
//本题主要解法是让数字符合小的数字在前大的在后的规则，不符合就删除
//如果都符合了，但是删除的次数还剩下例1566剩两次，就从后面删，因为大的在后面
#include<iostream>
//例903071
#include<string>
using namespace std;
string str;
int n;
int main() {
    cin >> str >> n;
    for (int i = 0; i  < n; i++) {
        int ind = str.size() - 1;//默认删最后面的数
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {//不符合小的在前打的在后
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");//替换为空串相当于删了
    }
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') flag = 1;
        if (flag) cout << str[i];
    }
    cout << endl;
    return 0;
}
