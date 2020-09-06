/*************************************************************************
	> File Name: P1424.cppmZ	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月18日 星期三 15时26分39秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int x, y, i;
    cin >> x >> y;
    long int sum = 0;
    for(i = 0; i < y; i++){
        if((x + i) % 7 % 6 == 0 || (x + i) % 7 % 7 == 0){
            continue;
        }
        else{
            sum = sum + 250;
        }
    }
    cout << sum << endl;
    return 0;
}
