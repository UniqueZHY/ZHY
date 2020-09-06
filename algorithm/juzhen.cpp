/*************************************************************************
	> File Name: juzhen.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月01日 星期五 11时23分34秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
void matrixChain(int n,int p[],int m[][100],int s[][100])//递推
{
       for(int i=1;i<=n;i++){//对角线先为0
                                m[i][i]=0;
                               }
       for(int r=2;r<=n;r++){//一共n-1个对角线
                                for(int i=1;i<=n-r+1;i++){//第i行
                                                                 int j=i+r-1;//在该行的对角线上的点对应的j值
                                                                 m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//初始化此时在i处取得最优解
                                                                 s[i][j]=i;
                                                                 for(int k=i+1;k<j;k++){//如果有更小的则被替换
                                                                                                   int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                                                                                                   if(t<m[i][j])
                                                                                        {
                                                                                                            m[i][j]=t;
                                                                                                            s[i][j]=k;
                                                                                                        
                                                                                        }
                                                                                               }
                                                             }
                               }

}
void print_optimal_parents(int s[100][100],int i,int j)//打印划分的结果
{
         if( i == j )
             cout<<"A"<<i;
         else
    {
                 cout<<"(";
                 print_optimal_parents(s,i,s[i][j]);
                 print_optimal_parents(s,s[i][j]+1,j);
                 cout<<")";
             
    }

     
}
int main()
{
        int p[1000];//每个矩阵的行数和最后一个的列数
        int m[100][100];//存储最优子结构
        int s[100][100];//存储当前结构的最优断点
        memset(p,0,sizeof(p));
        memset(m,0,sizeof(m));
        memset(s,0,sizeof(s));
        cout << "请输入矩阵的个数"<< endl;
        int n;
        cin >> n;
        cout << "请依次输入每个矩阵的行数和最后一个矩阵的列数"<< endl;
    for(int i=0;i<=n;i++){
                cin >> p[i];
            
    }
        matrixChain(n,p,m,s);
        cout <<"这些矩阵相乘的最少次数是"<<m[1][n]<<endl;

         cout<<"结果是:"<<endl;
         print_optimal_parents(s,1,n);
        cout<<endl;
        return 0;

}
