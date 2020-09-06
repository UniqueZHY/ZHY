/************************************
	> Mail: 
	> Created Time: 2019年09月22日 星期日 12时33分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int l, m, i, result, n;
    int a[100];
    cin >> m;
    for(i = 0; i < m; i++){
        cin >> a[i] >> a[i + 1];
    }
    for(i = 2; i < m; i++){
        if(a[i] < a[i - 1]){
           n = a[i+1] - a[i] + a[i-1] - a[i-2] + a[i-1] - a[i]; 
        }
        else{
            n = a[i+1] - a[i] + a[i-1] - a[i-2];
        }
    }    
    result = l + 1 - n;
    cout << result << endl;
    return 0;
}
