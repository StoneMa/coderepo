//迪杰斯特拉：单源最短路径；
#include <iostream>
#include <stdio.h>
#define MAXVEX 9 /* 最大顶点个数 */
#define INFINITY 65535 /** 用来表示权值无穷大 **/
using namespace std;
typedef struct
{
    char vexs[MAXVEX];///顶点的个数数组
    int edge[MAXVEX][MAXVEX];///各顶点间的边的权值矩阵
    int numV,numE;  ///顶点和边的数量；
}MGraph;///图结构体
void Dijkstra(MGraph G,int start, int path[] ,int ShortPath[])
{
    int i,j,k,minEdge;/// minEdge表示到目标结点的最小权值
    int visit[MAXVEX];///如果某个结点的最短路径已经找到，就设置visit[i] = 1;
    for(i=0;i<G.numV;i++)///初始化,把跟开始结点相连的边的权值都赋值给数组；
    {
        visit[i] = 0;
        ShortPath[i] = G.edge[start][i];///把邻接矩阵的start这一行的值付给ShortPath[]
        path[i] = 0;
    }
    ShortPath[start] = 0;///起始节点到自身的距离为0
    visit[start] = 1;///把起始节点设置成已访问
    /**     ======      主循环    ======       **/
    for(i=0;i<G.numV;i++)
    {
        minEdge = INFINITY;
        ///这一层for是为了寻找与当前结点相连的所有边中最小的权值
        for(j=0;j<G.numV;j++)
        {
            ///比较所有与当前结点相连的边的权值，每次记录较小的权值
            if(visit[j]==0 && ShortPath[j]<minEdge)
            {
                k = j;
                minEdge = ShortPath[j];
            }
        }
        visit[k] = 1;
        for(j=0;j<G.numV;j++)
        {
            ///如果从起点先通过结点k再到j的距离之和<从起点直接到j的距离，就记录前者为最短距离
            if(visit[j]==0 && minEdge+G.edge[k][j]<ShortPath[j])
            {
                ShortPath[j] = minEdge +G.edge[k][j];
                path[j] = k;
            }
        }
    }
}
