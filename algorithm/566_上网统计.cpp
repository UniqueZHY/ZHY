/*************************************************************************
	> File Name: 566_上网统计.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 15时13分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node {
    string id;
    vector <string> web;
};
int main() {
    vector <node> v;
    int n, m;
    string id, str;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> id >> str;
        bool flag = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].id == id) {
                v[j].web.push_back(str);
                flag = 1;
                break;
            }
        }
        if (!flag) {
            node temp;
            temp.id = id;
            temp.web.clear();
            temp.web.push_back(str);
            v.push_back(temp);
        }
    }
    for(int i = 0;i < v.size();i++){
        cout << v[i].id;
        for(int j = 0; j < v[i].web.size(); j++) {
            cout << " " << v[i].web[j];      
        }  
        cout <<endl;
    }
    return 0;
}
