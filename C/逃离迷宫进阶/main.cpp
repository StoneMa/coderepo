#include <iostream>
#include <stdio.h>
using namespace std;
#define inf 0x3fffffff;
#define M 105

char map[M][M];
int x_move[4] = {-1,0,1,0};
int y_move[4] = {0,1,0,-1};
int flag;
int time;
int k,l,h,ax,ay,wan[M][M];
void dfs(int x,int y,int dir)
{
    if(wan[x][y]>k) return;
    if(x==ax&&y==ay)
    {
       //if(wan[x][y]<=k)
        //{
        flag = 1;
        //}
        //这样需不需要再次判断wan[][];
        return ;
    }
    if(wan[x][y] == k && x!=ax&&y!=ay)
        return ;
    for(int i=0;i<4;i++)
    {
        int tx = x+x_move[i];
        int ty = y+y_move[i];
            if(tx<0||tx>=l||ty<0||ty>=h)
                continue;
            if(map[tx][ty] =='*'|| wan[tx][ty]<wan[x][y])
                continue;
            if(dir!=-1 && i!=dir && wan[tx][ty]<=wan[x][y])
                continue;
        wan[tx][ty] = wan[x][y];
        if(dir !=-1 && i !=dir)
            wan[tx][ty] ++;
        dfs(tx,ty,i);
        if (flag)
            return;
    }
}
int main()
{
    int t,sx,sy;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&l,&h);
    for(int i=0;i<l;i++)
        scanf("%s",map[i]);
    scanf("%d%d%d%d%d",&k,&sy,&sx,&ay,&ax);
    sx--;sy--; ax--; ay--;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<h;j++)
            wan[i][j] = inf;
    }
    wan[sx][sy] = 0;
    flag = 0;
    dfs(sx,sy,-1);
    if(flag)
        printf("yes\n");
    else
        printf("no\n");
    }
        return 0;
}
