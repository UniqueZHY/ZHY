/***************************************************************mZ********
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 16时06分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
    int poww(int a, int b) {
        int ans = 1;
        while(b != 0) {
            if(b & 1){
                ans = ans * a;
            }
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
 int main(){
    int n , ans;
   // cin >> a >> n;
     cin >> n;
    ans = poww(2, n);
     cout << ans  << endl;
    return 0;   
}
