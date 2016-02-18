//�Ͻ�˹��������Դ���·����
#include <iostream>
#include <stdio.h>
#define MAXVEX 9 /* ��󶥵���� */
#define INFINITY 65535 /** ������ʾȨֵ����� **/
using namespace std;
typedef struct
{
    char vexs[MAXVEX];///����ĸ�������
    int edge[MAXVEX][MAXVEX];///�������ıߵ�Ȩֵ����
    int numV,numE;  ///����ͱߵ�������
}MGraph;///ͼ�ṹ��
void Dijkstra(MGraph G,int start, int path[] ,int ShortPath[])
{
    int i,j,k,minEdge;/// minEdge��ʾ��Ŀ�������СȨֵ
    int visit[MAXVEX];///���ĳ���������·���Ѿ��ҵ���������visit[i] = 1;
    for(i=0;i<G.numV;i++)///��ʼ��,�Ѹ���ʼ��������ıߵ�Ȩֵ����ֵ�����飻
    {
        visit[i] = 0;
        ShortPath[i] = G.edge[start][i];///���ڽӾ����start��һ�е�ֵ����ShortPath[]
        path[i] = 0;
    }
    ShortPath[start] = 0;///��ʼ�ڵ㵽����ľ���Ϊ0
    visit[start] = 1;///����ʼ�ڵ����ó��ѷ���
    /**     ======      ��ѭ��    ======       **/
    for(i=0;i<G.numV;i++)
    {
        minEdge = INFINITY;
        ///��һ��for��Ϊ��Ѱ���뵱ǰ������������б�����С��Ȩֵ
        for(j=0;j<G.numV;j++)
        {
            ///�Ƚ������뵱ǰ��������ıߵ�Ȩֵ��ÿ�μ�¼��С��Ȩֵ
            if(visit[j]==0 && ShortPath[j]<minEdge)
            {
                k = j;
                minEdge = ShortPath[j];
            }
        }
        visit[k] = 1;
        for(j=0;j<G.numV;j++)
        {
            ///����������ͨ�����k�ٵ�j�ľ���֮��<�����ֱ�ӵ�j�ľ��룬�ͼ�¼ǰ��Ϊ��̾���
            if(visit[j]==0 && minEdge+G.edge[k][j]<ShortPath[j])
            {
                ShortPath[j] = minEdge +G.edge[k][j];
                path[j] = k;
            }
        }
    }
}
