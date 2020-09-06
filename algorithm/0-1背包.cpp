/*************************************************************************
	> File Name: 0-1背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月28日 星期四 15时21分07秒
 ************************************************************************/

#include<iostream>
#include<queue>

#include<cstring>

using namespace std;

const int maxn=10;

struct node{
    
        int cv,lv;//当前价值，剩余价值

        int lw;//剩余容量

        int id;//物品序号

        int x[maxn];//解向量

    node(){
        
                memset(x,0,sizeof(x));

            
    }

    node(int cvv,int lvv,int lww,int idd){
        
                memset(x,0,sizeof(x));

                cv=cvv;

                lv=lvv;

                lw=lww;

                id=idd;

            
    }


};

int n,W;//物品种数，背包容量

int w[maxn],v[maxn];//重量和价值

int bestx[maxn];//最优解

int bestv;//最优价值

void init(){
    
        memset(w,0,sizeof(w));

        memset(v,0,sizeof(v));

        memset(bestx,0,sizeof(bestx));

        bestv=0;


}

void bfs(){
    
        queue<node> q;

        int sumv=0;

        int i;

        for(i=1; i<=n; ++i)

            sumv+=v[i];

        q.push(node(0,sumv,W,1));

    while(!q.empty()){
        
                node live;

                live=q.front();

                q.pop();

                int t=live.id;//当前处理物品的序号

        if(t>n||live.lw==0){
            
            if(live.cv>=bestv){

                                for(int i=1; i<=n; ++i)

                                    bestx[i]=live.x[i];

                                bestv=live.cv;

                            
            }

                        continue;

                    
        }

                if(live.cv+live.lv<bestv)  continue;

        if(live.lw>=w[t]){
            
                        node lchild(live.cv+v[t],live.lv-v[t],live.lw-w[t],t+1);

                        for(int i=1; i<=n; ++i)

                            lchild.x[i]=live.x[i];

                        lchild.x[t]=1;

                        if(lchild.cv>bestv)//注意要更新最优值

                            bestv=lchild.cv;

                        q.push(lchild);

                    
        }

                if(live.cv+live.lv-v[t]>=bestv)//满足限界条件，可以生成右孩子

                {
                    
                                node rchild(live.cv,live.lv-v[t],live.lw,t+1);

                                for(int i=1; i<=n; ++i)

                                    rchild.x[i]=live.x[i];

                                rchild.x[t]=0;

                                q.push(rchild);

                            
                }

                    
    }


}

void output(){
    
        cout<<"可装载物品的最大价值为："<<bestv<<endl;

        cout<<"装入的物品为：";

        for(int i=1; i<=n; ++i)

            if(bestx[i])

                cout<<i<<" ";

        cout<<endl;

        return ;


}

int main(){
    
        init();

        cout<<"请输入物品个数：";

        cin>>n;

        cout<<"请输入背包容量：";

        cin>>W;

        cout<<"请依次输入物品的重量和价值：";

        for(int i=1; i<=n; ++i)

            cin>>w[i]>>v[i];

        bfs();

        output();

        return 0;


}
