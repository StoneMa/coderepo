#include <iostream>
#include <stdio.h>
using namespace std;

typedef int boolean;
typedef char VertexType;///顶点类型；
typedef int EdgeType;///边上的权值类型；
#define MAX 100
#define INFINITY 65535
boolean visited[MAX];
typedef struct
{
    VertexType vexs[MAX];
    EdgeType arc[MAX][MAX];
    int numVertexes;
}MGraph;

///邻接矩阵的深度优先递归算法
void DFS(MGraph G,int i)
{
    int j;
    visited[i] = true;
    printf("%c",G.vexs[i]);
    for(j=0;j<G.numVertexes;j++)
    {
        if(G.arc[i][j] == 1&&visited[j]==false)
            DFS(G,j);
    }
}
///邻接矩阵的深度优先遍历；
void DFSTraverse(MGraph G)
{
    int i;
    for( i =0; i<G.numVertexes;i++)
    {
        visited[i] = false;///初始化所有顶点的状态，使其都是为访问过的。
    }
    for(i=0;i<G.numVertexes;j++)
    {
        if(visited[i] == false)
        {
            DFS(G.j);///对于访问过的顶点调用DFS，若是连通图，只执行一次
        }
    }
}
///邻接表的深度优先搜索；
void DFS(GraphAdjList GL,int i)
{
    EdgeNode *p;
    visited[i] = true;
    printf("%c",GL->adjList[i].data);
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(visited[p->adjvex]==false)
        {
            DFS(GL,p->adjvex);
        }
        p=p->next;
    }
}
///邻接表的深度遍历
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for( i = 0;i<GL->numVertexes;i++)
    {
        visited[i] = false;
    }
    for(i=0;i<GL->numVertexes;i++)
        if(visited[i]==false)
            DFS(GL,i);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
