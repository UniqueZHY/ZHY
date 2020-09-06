/*************************************************************************
	> File Name: 191_素数距离.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月30日 星期六 15时19分47秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
//#define max_n 8000000
using namespace std;
int n[8000005] = {1,1};
void init() {
    for(int i = 2; i * i <= 8000000; i++){
        if(!n[i]) {
            for(int j = 2; i * j < 8000000; j++){
                n[i * j] = 1;
            }
        }
    }
}
int main() {
    init();
    int l, r;
    cin >> l >> r;
    int min1 = - 1, min2, max1, max2;
    for(int i = l; i < r; i++){
        if(!n[i]){
            int next = i + 1;
            while(n[next]){
                next++;
            }
            if(next > r) {
                break;
            }   
            if(min1 == -1){
                min1 = max1 = i;
                min2 = max2 = next;
            } else if(next - i > max2 - max1) {
                max1 = i;
                max2 = next;
            
            } else if(next - i < min2 - min1) {
                min1 = i;
                min2 = next;
            }
        }
    }
    if(min1 == -1) printf("There are no adjacent primes.");
    else printf("%d,%d are closest, %d,%d are most distant.", min1, min2, max1, max2);
    return 0;
}
