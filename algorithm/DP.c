/*************************************************************************
	> File Name: DP.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年07月10日 星期三 20时04分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
//stellar myself！
const int maxn=1000;
int m[maxn][maxn];
int w[maxn],v[maxn];
int C,N;
void add(int i,int j){
    if (j<w[i])
        m[i][j]=m[i-1][j];
    else
        m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
}
int main(){
    cin>>N>>C;
    for(int i=1;i<=N;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=C;j++){
            add(i,j);
        }
    }
    int big=m[1][1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=C;j++){
            if (m[i][j]>big) big=m[i][j];
        }
    }
    cout<<big<<endl;
    return 0;
} 
