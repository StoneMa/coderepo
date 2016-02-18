#include <iostream>
#include <stdio.h>
#define MAXVEX 9 /** 最大定点数 **/
#define INFINITY 65535 /** 用来表示权值为无穷大 **/
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];
using namespace std;

///定义一个图 的数据结构

typedef char VertexType; /** 顶点类型 **/
typedef int EdgeType;    /** 边上权值的类型 **/
typedef struct
{
    VertexType vexs[MAXVEX];   /** 顶点表 **/
    EdgeType arc[MAXVEX][MAXVEX];   /**邻接矩阵，可看做边表 **/
    int numVertexes,numEdges;  /** 图中当前顶点数 和 边数 **/
}MGraph;

void ShortestPath_Dijkstra(MGraph G,int v0,Patharc *p,ShortPathTable *D)
{
    int v,w,k,min;
    int final[MAXVEX];  /** final[w] = 1表示求得V0到Vw的最短路径；**/
    for (v=0,v<G.numVertexes;v++)  /** 初始化数据 **/
    {
        final[v] = 0; /** 0表示所有节点的最短路径状态未知 **/
        (*D)[v] = G.arc[v0][v]; /** 将与v0相关的连的顶点间的连线加上权值 **/
        (*p)[v] = 0;    /** 初始化路径数组P为0 **/
    }
    (*D)[v0] = 0;   /**到自身路径长度为0 **/
    final[v0] = 1;   /** v0到v0不需要求路径长度 **/

    /*=============== 开始主循环================ */
    for(v=0;v<G.numVertexes;v++)///***这里的v只是表示循环次数，下面代码中并没有用到v作为角标
    {
        min = INFINITY;
        // 第一层for循环是为了寻找离已经确定最短距离的图相连的最短距离的中继点，
        for(w = 0;w<G.numVertexes;w++)  ///这一层for循环目的是为了寻找一个未标记过的，离当前w的上一个结点最近的结点
        {
            if(!final[w] && (*D)[w]<min)  ///判断G.numVertexes次，查找出于final[w] = 0 的，而且和w的上一个结点有连接关系的结点
            {
                k = w; ///记录下离w的上一个结点最近的w节点的角标
                min = (*D)[w]; ///每次循环都存储权值，但最终只存储最小权值
            }
        }
        final[k] = 1; ///将上面找到的结点k的final置为1，表示源点到该结点的最短距离已经找到
        for(w=0;w<G.numVertexes;w++)///以之前的中继点为源点寻找与中继点相连的所有顶点中权值最小的边
        {
       /*在所有跟w结点相连的结点中找到权值最小的边，
          并把新的边长更新到（*D）[w],
          把当前中继结点k放入到路径数组（*P）[w]中，这里要注意的是（*p）[w] = k,表示：从源点到w结点的路径的上一个结点是k；
       */
        if(final[w]==0 && min+G.arc[k][w]<(*D)[w])
            {
                (*D)[w] = min + G.arc[k][w];
                (*p)[w] = k;
            }
        }
    }
}
