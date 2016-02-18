#include<iostream>
#include<string.h>
using namespace std;

int set[1001]; //集全
bool flag[1001]; //用于计算（不相交）集合的个数

int find(int x)  //查找
{
if(set[x]==-1)  //已经是根结点
return x;
return set[x]=find(set[x]); //找出根结点并返回
}

int merge(int a,int b)  //合并
{
int fa=find(a);  //a的根结点
int fb=find(b);  //b的根结点
if(fa==fb)       //a与b有相同的根结点，即a,b为同一集合
return 0;
set[fa]=fb;      //若a与b的根结点不同，则a的根结点连接b的根结点
return 1;
}

int main()
{
int N,M,i,x,y,k;
while(cin>>N>>M,N)
{
memset(set,-1,sizeof(set));  //初始化
memset(flag,0,sizeof(flag));
for(i=0;i<M;i++)  //输入且合并
{
cin>>x>>y;
merge(x,y);
}
for(i=1;i<=N;i++)  //将所有的根标记，即标记所有的集合
{
flag[find(i)]=1;
}
k=0;
for(i=1;i<=N;i++)  //计算出集合的个数
{
if(flag[i]==1)
k++;
}
cout<<k-1<<endl;
}
return 1;
}
