#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 10

using namespace std;
int a[N],vis[N],result[N];
int n,t=0;

void dfs(int a[],int t);
int main()
{
    printf("输入你想要排序的个数：\n");
    scanf("%d",&n);
    printf("输入这%d个需要全排列的数字:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    memset(vis,0,sizeof(vis));
    memset(result,0,sizeof(result));
    dfs(a,t);

    return 0;
}

void dfs(int a[],int t)
{
        if(t==n)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d",result[j]);
            }
            printf("\n");
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                {
                    vis[i]=1;
                    result[t] = a[i];
                    dfs(a,t+1);
                    vis[i] = 0;
                }
            if(vis[i])
                {
                    continue;
                }
        }
}
