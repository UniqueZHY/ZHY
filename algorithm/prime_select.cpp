/*************************************************************************
	> File Name: prime_select.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年10月27日 星期日 14时48分05秒
 ************************************************************************/

#include<iostream>
#define max_n 100
using namespace std;
int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <+ max_n; i++){
        if (!prime[i]) {
            prime[++prime[0]] = i;
            for(int j = i; j * i <= max_n; j++) {
                prime[j * i] = 1;
            }
        }
    }
    return ;
}
int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        cout << prime[i] << endl;
    }

}
