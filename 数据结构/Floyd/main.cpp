#include <iostream>
#include <stdio.h>
#define MAXVEX 100
#define INFINITY
typedef char VertexType;
typedef int EdgeType;
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int shortPathTable[MAXVEX][MAXVEX];

using namespace std;
///ͼ�ṹ����
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType matirx[MAXVEX][MAXVEX];//�ڽӾ��󣬱߱�
    int numVertexes,numEdges;
}MGraph;
///Floyd�㷨��������ͼG�и�������v��������������w���·��P[v][w]�����Ȩ·������D[v][w];
void ShortestPath_Floyd(MGraph G,Pathmatirx *P,shortPathTable *D)
{
    int v,w,k;
    for(v=0;v<G.numVertexes;++v)
    {
        for(w=0;w<G.numVertexes;++w)
        {
            (*D)[v][w] = G.matirx[v][w]; ///D[v][w]��Ӧ��ֵ��Ϊ��Ӧ����Ȩֵ
            (*P)[v][w] = w; ///��ʼ��P
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
                    ///����ܼ����±�Ϊk�Ķ���֮��v��w�ľ������һ�Σ�*D��[v][w]�м�¼��ֵҪС��ô�Ͱѵ�ǰ����
                    ///���뵽��������У�
                    (*D)[v][w] = (*D)[v][w] + (*D)[k][w];   ///v����w��·�����ȸ���Ϊ����k�������µ�·������
                    (*P)[v][w] = (*P)[v][k];  ///·�����þ����±�Ϊk�Ķ��㣻
                }
            }
        }
    }
}
