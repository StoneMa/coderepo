#include <iostream>
#include <stdio.h>
using namespace std;
int vis[5];
int result[5];
void dfs(int n,int i)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
            {
                printf("%d",result[j]);
            }
            printf("\n");
    }
    for(int k=0;k<n;k++)
    {
        if(vis[k]==0)
        {
            vis[k] = 1;
            result[i] = k;
            dfs(n,i+1);
            vis[k] = 0;
        }
    }

}
int main()
{
    dfs(5,0);
    return 0;
}
