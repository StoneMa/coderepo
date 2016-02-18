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

void BFSTraverse(MGraph G)
{
    int i,j;
    Queue Q;
    for(i=0;i<G.numVertexes;i++)
    {
        visited[i] = false;
    }
    InitQueue(&Q);
    for(i=0;i<G.numVertexes;i++)
    {
        if(visited[i]=false)
        {
            visited[i] = true;
            printf("%c",G.vexs[i]);
            EnQueue(&Q,i);
            while(QueueEmpty(Q))
            {
                deque(&Q,i);
                for(j=0;j<G.numVertexes;j++)
                {
                    if(G.arc[i][j] == 1&&visited[j])
                    {
                        visited[j] = true;
                        printf("%c",G.vexs[j]);
                        EnQueue(&Q,j);
                    }
                }
            }
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
