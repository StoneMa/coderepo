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
    flag[S]=1;//�Ƚ�����ʼ��
    int t;//���ܻ�û�н⣬���Բ�����������
    while(!q.empty())
    {
        t=q.front();

        q.pop();//ȡ�ö�ͷԪ��֮�����ϳ���
        if(t==E)
            break;//ƥ��ɹ�
        int next=t+floor[t];//i,ki

        if(next>=1 && next<=B && flag[next]==0)//����
        {
            q.push(next);
            flag[next]=flag[t]+1;
            //printf("%d",next);
        }

        next=t-floor[t];//i,ki
        if(next>=1 && next<=B && flag[next]==0)//����
        {
            q.push(next);
            flag[next]=flag[t]+1;
            //printf("%d",next);
        }

    }
    if(t!=E)
        flag[B]=0;//ƥ�䲻�ɹ�
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
        printf("%d\n",flag[B]-1);//��Ϊһ��ʼ��flag[A]=1
    }
    return 0;
}
