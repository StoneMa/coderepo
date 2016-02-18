#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

int N,A,B;
int floor[255],flag[255];

void BFS(int S,int E)
{

    queue<int>q;
    q.push(S);
    flag[S]=1;//先将它初始化
    int t;//可能会没有解，所以不在里面声明
    while(!q.empty())
    {
        t=q.front();

        q.pop();//取得队头元素之后，马上出队
        if(t==E)
            break;//匹配成功
        int next=t+floor[t];//i,ki

        if(next>=1 && next<=B && flag[next]==0)//向上
        {
            q.push(next);
            flag[next]=flag[t]+1;
            //printf("%d",next);
        }

        next=t-floor[t];//i,ki
        if(next>=1 && next<=B && flag[next]==0)//向下
        {
            q.push(next);
            flag[next]=flag[t]+1;
            //printf("%d",next);
        }

    }
    if(t!=E)
        flag[B]=0;//匹配不成功
}
int main()
{
    while(scanf("%d",&N)&& N!=0)
    {
        scanf("%d %d",&A,&B);
            for(int i=1;i<=N;i++)
            {
                scanf("%d",&floor[i]);
            }
            memset(flag,0,sizeof(flag));
        BFS(A,B);
        printf("%d\n",flag[B]-1);//因为一开始将flag[A]=1
    }
    return 0;
}
