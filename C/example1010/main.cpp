#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
//迷宫地图
//X: 墙壁，小狗不能进入
//S: 小狗所处的位置
//D: 迷宫的门
//. : 空的方格
char map[9][9];
int n,m,t,di,dj; //(di,dj):门的位置
bool escape;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}}; //分别表示下、上、左、右四个方向
void dfs(int si,int sj,int cnt)  //表示起始位置为(si,sj)，要求在第cnt秒达到门的位置
{
    int i,temp;
    if( si>n || sj>m || si<=0 || sj<=0 ) return;

    if( si==di && sj==dj && cnt==t )
    {
        escape = 1;
        return;
    }

    //abs(x-ex) + abs(y - ey)表示现在所在的格子到目标格子的距离（不能走对角线）
    //t-cnt是实际还需要的步数，将他们做差
    //如果temp < 0或者temp为奇数，那就不可能到达！
    temp = (t-cnt) - abs(si-di) - abs(sj-dj);

    if( temp<0 || temp&1 ) return;

    for( i=0; i<4; i++ )
    {
        if( map[ si+dir[i][0] ][ sj+dir[i][1] ] != 'X')
        {
            map[ si+dir[i][0] ][ sj+dir[i][1] ] = 'X';

                dfs(si+dir[i][0], sj+dir[i][1], cnt+1);

            if(escape) return;

            map[ si+dir[i][0] ][ sj+dir[i][1] ] = '.';
        }
    }

    return;
}
int main()
{
    int i,j,si,sj;

    while( cin >> n >> m >> t)
    {
        if( n==0 && m==0 && t==0 )break;
        int wall = 0;
        for( i=1; i<=n; i++ )
            for( j=1; j<=m; j++ )
            {
                cin >> map[i][j];
                if(map[i][j]=='S') { si=i; sj=j; }
                else if( map[i][j]=='D' ) { di=i; dj=j; }
                else if( map[i][j]=='X' ) wall++;
            }

            if( n*m-wall <= t )
            {
                cout << "NO" << endl;
                continue;
            }

            escape = 0;
            map[si][sj] = 'X';

            dfs( si, sj, 0 );

            if( escape ) cout << "YES" << endl;
            else cout << "NO" << endl;
    }

    return 0;
}
