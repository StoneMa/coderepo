#include <iostream>
#include <cstdio>
#define N 1005
#define inf  0x0F0F0F0F
using namespace std;
int low[N];
void Dijkstra(int cost[][N],int start, int n){
    int vis[N],edge,k;
    for(int  i =0 ; i<n; i++){
        low[i] = cost[start][i];
        vis[i]=0;
    }
    vis[start] = 1 ;
    low[start] = 0;
    for(int i =1; i<n; i++)
    {
        edge = inf;
        for(int j=0; j<n; j++)
        {
            if(vis[j] == 0 && edge>low[j])
            {
                edge = low[j];
                k=j;
            }
        }
        vis[k] =1;
        for(int j = 0; j<n; j++)
        {
            if(vis[j] == 0 && low[j]>low[k] + cost[k][j])
                low[j] = low[k]+cost[k][j];
        }
    }
}
int main(){
    printf("------\n");
    int g[N][N];
    int m,n;
    int s,t;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j) g[i][j] = inf;
            else     g[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++)
    {
        int a,b,x;
        cin>>a>>b>>x;
        if(g[a][b]>x)
              g[a][b] = g[b][a] = x;
    }
    cin>>s>>t;
    Dijkstra(g,s,n);
    for(int i=0; i<n; i++)
    {
        cout<<low[i]<<" ";
    }
    return 0;
}

