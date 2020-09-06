/***************************************************************mZ********
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 16时06分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
    int pow(int a, int b, int c) {
        int ans = 1;
        while(b != 0) {
            if(b & 1){
                ans = ans * a % c;
            }
            a = a * a % c;
            b >>= 1;
        }
        return ans;
    }
 int main(){
     int a;
     while(cin >> a){
         int b, c, ans;
         cin >> b >> c;
         ans = pow(a, b, c);
         cout <<  ans << endl;
     }
    return 0;   
}
