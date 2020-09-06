/*************************************************************************
	> File Name: 378_字符串括号匹配2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 09时12分24秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
    stack <char> s;
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '(' :
            case '[' :
            case '{' :
                   s.push(str[i]);
                   break;
            case ')' :
                   if (s.top() == '(') s.pop();
                   break;
            case ']' :
                   if (s.top() == '[') s.pop();
                   break;
            case '}' :
                   if (s.top() == '{') s.pop();
                   break;
        }
    }
    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    
return 0;
}
