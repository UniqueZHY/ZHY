/*************************************************************************
	> File Name: 379_仓库日志.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 15时22分30秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int arr[200005];

int main() {
    int n, m, x, top = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        switch (m) {
            case 0 : 
                cin >> x;
                arr[++top] = max(arr[top - 1], x);
                break;
            case 1 :
                top--; break;
            case 2 :
                cout << arr[top] << endl; break;
                
        }
    }
    return 0;
}
/*int main() {
    int n, m, x;
    cin >> n;
    while (n--) {
        cin >> m;
        if (m == 0) {
            cin >> x;
            a.push(x);
            if (b.empty() || x > b.top()) {
                b.push(x);
            } else {
                b.push(b.top());
            }
        }
        if (m == 1) {
            a.pop();
            b.pop();
        }
        if (m == 2) {
            if (b.empty()) cout << "0" << endl;
            else cout << b.top() << endl ;
        }
    }
    return 0;
}*/
