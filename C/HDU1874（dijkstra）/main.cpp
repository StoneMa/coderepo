#include <stdio.h>
const int N = 1009;
const int inf = (1<<30);
int g[N][N];
int ans[N];

int Dijkstra(int cost[][N],int start,int end, int n){
    int vis[N],edge,k;
    for(int  i =0 ; i<n; i++){
        ans[i] = cost[start][i];
        vis[i]=0;
    }
    vis[start] = 1 ;
    ans[start] = 0;
    for(int i =1; i<n; i++){
        edge = inf;
        for(int j=0; j<n; j++){
            if(vis[j] == 0 && edge>ans[j]){
                edge = ans[j];
                k=j;
            }
        }
        if(vis[end]==0 && edge==inf)  return -1;
        vis[k] =1;
        for(int j = 0; j<n; j++){
            if(vis[j] == 0 && ans[j]>ans[k] + cost[k][j])
                ans[j] = ans[k]+cost[k][j];
        }
    }
    return 0;
}
void init(int n){
         for(int i=0; i<n; i++){
              for(int j=0; j<n; j++){
                     if(i!=j) g[i][j] = inf;
                     else     g[i][j] = 0;
             }
         }
}
int main(){
    int m,n;
    int s,t;
    //freopen("Text.txt","r",stdin);
    //freopen("Text1.txt","w",stdout);
    while(scanf("%d %d",&n,&m)!=EOF){
    init(n);
    for(int i=0; i<m; i++){
        int a,b,x;
        scanf("%d %d %d",&a,&b,&x);
        if(g[a][b]>x)
            g[a][b] = g[b][a] = x;
    }
    scanf("%d %d",&s,&t);
    int tag  = Dijkstra(g,s,t,n);
   if(tag==-1)
        printf("-1\n");
   else
        printf("%d\n",ans[t]);
    }
    return 0;

}
