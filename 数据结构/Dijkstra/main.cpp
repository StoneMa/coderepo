#include <iostream>
#include <stdio.h>
#define MAXVEX 9 /** ��󶨵��� **/
#define INFINITY 65535 /** ������ʾȨֵΪ����� **/
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];
using namespace std;

///����һ��ͼ �����ݽṹ

typedef char VertexType; /** �������� **/
typedef int EdgeType;    /** ����Ȩֵ������ **/
typedef struct
{
    VertexType vexs[MAXVEX];   /** ����� **/
    EdgeType arc[MAXVEX][MAXVEX];   /**�ڽӾ��󣬿ɿ����߱� **/
    int numVertexes,numEdges;  /** ͼ�е�ǰ������ �� ���� **/
}MGraph;

void ShortestPath_Dijkstra(MGraph G,int v0,Patharc *p,ShortPathTable *D)
{
    int v,w,k,min;
    int final[MAXVEX];  /** final[w] = 1��ʾ���V0��Vw�����·����**/
    for (v=0,v<G.numVertexes;v++)  /** ��ʼ������ **/
    {
        final[v] = 0; /** 0��ʾ���нڵ�����·��״̬δ֪ **/
        (*D)[v] = G.arc[v0][v]; /** ����v0��ص����Ķ��������߼���Ȩֵ **/
        (*p)[v] = 0;    /** ��ʼ��·������PΪ0 **/
    }
    (*D)[v0] = 0;   /**������·������Ϊ0 **/
    final[v0] = 1;   /** v0��v0����Ҫ��·������ **/

    /*=============== ��ʼ��ѭ��================ */
    for(v=0;v<G.numVertexes;v++)///***�����vֻ�Ǳ�ʾѭ����������������в�û���õ�v��Ϊ�Ǳ�
    {
        min = INFINITY;
        // ��һ��forѭ����Ϊ��Ѱ�����Ѿ�ȷ����̾����ͼ��������̾�����м̵㣬
        for(w = 0;w<G.numVertexes;w++)  ///��һ��forѭ��Ŀ����Ϊ��Ѱ��һ��δ��ǹ��ģ��뵱ǰw����һ���������Ľ��
        {
            if(!final[w] && (*D)[w]<min)  ///�ж�G.numVertexes�Σ����ҳ���final[w] = 0 �ģ����Һ�w����һ����������ӹ�ϵ�Ľ��
            {
                k = w; ///��¼����w����һ����������w�ڵ�ĽǱ�
                min = (*D)[w]; ///ÿ��ѭ�����洢Ȩֵ��������ֻ�洢��СȨֵ
            }
        }
        final[k] = 1; ///�������ҵ��Ľ��k��final��Ϊ1����ʾԴ�㵽�ý�����̾����Ѿ��ҵ�
        for(w=0;w<G.numVertexes;w++)///��֮ǰ���м̵�ΪԴ��Ѱ�����м̵����������ж�����Ȩֵ��С�ı�
        {
       /*�����и�w��������Ľ�����ҵ�Ȩֵ��С�ıߣ�
          �����µı߳����µ���*D��[w],
          �ѵ�ǰ�м̽��k���뵽·�����飨*P��[w]�У�����Ҫע����ǣ�*p��[w] = k,��ʾ����Դ�㵽w����·������һ�������k��
       */
        if(final[w]==0 && min+G.arc[k][w]<(*D)[w])
            {
                (*D)[w] = min + G.arc[k][w];
                (*p)[w] = k;
            }
        }
    }
}
