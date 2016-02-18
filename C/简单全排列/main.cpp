#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 100
using namespace std;
int use[N];
int a[N];
int n;
void dfs(int n,int t);
int main()
{
    memset(use,0,sizeof(use));
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    dfs(n,1);
    return 0;
}

void dfs(int n,int t)
{

    for(int i = 1;i<=n;i++){
        if(use[i]==0){
            use[i]=1;
            a[t] = i;
            dfs(n,t+1);
            use[i]=0;
        }

    }
           if( t == n+1)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d",a[j]);
            }
            printf("\n");
        }
}
