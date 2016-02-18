#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int prime[40]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};//素数打表，因为n最大是20，所以只要打到40
int vis[21],a[21];
int n;
void dfs(int num)
    {
        int i;
        if(num==n&&prime[a[num-1]+a[0]])
        {
            for(i=0;i<num-1;i++) printf("%d ",a[i]);
            printf("%d\n",a[num-1]);//这里一定要用这样的打印方式，而不能用将上面的printf中的num-1直接改成num，因为最后一个数字之后没有空格。
        }
        else
        {
            for(i=2;i<=n;i++)
            {
                if(vis[i]==0)//表示没有使用过;
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
