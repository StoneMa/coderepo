#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int prime[40]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};//���������Ϊn�����20������ֻҪ��40
int vis[21],a[21];
int n;
void dfs(int num)
    {
        int i;
        if(num==n&&prime[a[num-1]+a[0]])
        {
            for(i=0;i<num-1;i++) printf("%d ",a[i]);
            printf("%d\n",a[num-1]);//����һ��Ҫ�������Ĵ�ӡ��ʽ���������ý������printf�е�num-1ֱ�Ӹĳ�num����Ϊ���һ������֮��û�пո�
        }
        else
        {
            for(i=2;i<=n;i++)
            {
                if(vis[i]==0)//��ʾû��ʹ�ù�;
                {
                    if(prime[i+a[num-1]])
                    {
                        vis[i]=-1;
                        a[num] = i;
                        num++;
                        dfs(num);
                        vis[i]=0;
                        num--;
                    }
                }
            }
        }
    }

int main()
{
    int numb = 0;
    while(scanf("%d",&n)!=EOF)
    {
        numb++;
        printf("Case %d:\n",numb);
        memset(vis,0,sizeof(vis));
        a[0] = 1;
        dfs(1);
        printf("\n");

    }
    return 0;
}
