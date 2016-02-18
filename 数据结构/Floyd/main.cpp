#include <iostream>
#include <stdio.h>
#define MAXVEX 100
#define INFINITY
typedef char VertexType;
typedef int EdgeType;
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int shortPathTable[MAXVEX][MAXVEX];

using namespace std;
///图结构声明
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType matirx[MAXVEX][MAXVEX];//邻接矩阵，边表
    int numVertexes,numEdges;
}MGraph;
///Floyd算法，求网络图G中各个顶点v到其他各个顶点w最短路径P[v][w]及其带权路径长度D[v][w];
void ShortestPath_Floyd(MGraph G,Pathmatirx *P,shortPathTable *D)
{
    int v,w,k;
    for(v=0;v<G.numVertexes;++v)
    {
        for(w=0;w<G.numVertexes;++w)
        {
            (*D)[v][w] = G.matirx[v][w]; ///D[v][w]对应的值即为对应点间的权值
            (*P)[v][w] = w; ///初始化P
        }
    }
    for( k =0;k<G.numVertexes;++k)
    {
        for(v = 0;v<G.numVertexes;++v)
        {
            for(w=0;w<G.numVertexes;++w)
            {
                if((*D)[v][w]>(*D)[v][w]+(*D)[k][w])
                {
                    ///如果能加入下标为k的顶点之后，v到w的距离比上一次（*D）[v][w]中记录的值要小那么就把当前顶点
                    ///加入到顶点矩阵中，
                    (*D)[v][w] = (*D)[v][w] + (*D)[k][w];   ///v到大w的路径长度更新为经过k顶点后的新的路径长度
                    (*P)[v][w] = (*P)[v][k];  ///路径设置经过下标为k的顶点；
                }
            }
        }
    }
}
