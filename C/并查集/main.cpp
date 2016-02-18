#include<iostream>
#include<string.h>
using namespace std;

int set[1001]; //��ȫ
bool flag[1001]; //���ڼ��㣨���ཻ�����ϵĸ���

int find(int x)  //����
{
if(set[x]==-1)  //�Ѿ��Ǹ����
return x;
return set[x]=find(set[x]); //�ҳ�����㲢����
}

int merge(int a,int b)  //�ϲ�
{
int fa=find(a);  //a�ĸ����
int fb=find(b);  //b�ĸ����
if(fa==fb)       //a��b����ͬ�ĸ���㣬��a,bΪͬһ����
return 0;
set[fa]=fb;      //��a��b�ĸ���㲻ͬ����a�ĸ��������b�ĸ����
return 1;
}

int main()
{
int N,M,i,x,y,k;
while(cin>>N>>M,N)
{
memset(set,-1,sizeof(set));  //��ʼ��
memset(flag,0,sizeof(flag));
for(i=0;i<M;i++)  //�����Һϲ�
{
cin>>x>>y;
merge(x,y);
}
for(i=1;i<=N;i++)  //�����еĸ���ǣ���������еļ���
{
flag[find(i)]=1;
}
k=0;
for(i=1;i<=N;i++)  //��������ϵĸ���
{
if(flag[i]==1)
k++;
}
cout<<k-1<<endl;
}
return 1;
}
