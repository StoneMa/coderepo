#include <iostream>
#include <stdio.h>
using namespace std;

typedef int boolean;
typedef char VertexType;///�������ͣ�
typedef int EdgeType;///���ϵ�Ȩֵ���ͣ�
#define MAX 100
#define INFINITY 65535
boolean visited[MAX];
typedef struct
{
    VertexType vexs[MAX];
    EdgeType arc[MAX][MAX];
    int numVertexes;
}MGraph;

///�ڽӾ����������ȵݹ��㷨
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
///�ڽӾ����������ȱ�����
void DFSTraverse(MGraph G)
{
    int i;
    for( i =0; i<G.numVertexes;i++)
    {
        visited[i] = false;///��ʼ�����ж����״̬��ʹ�䶼��Ϊ���ʹ��ġ�
    }
    for(i=0;i<G.numVertexes;j++)
    {
        if(visited[i] == false)
        {
            DFS(G.j);///���ڷ��ʹ��Ķ������DFS��������ͨͼ��ִֻ��һ��
        }
    }
}
///�ڽӱ���������������
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
///�ڽӱ����ȱ���
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
