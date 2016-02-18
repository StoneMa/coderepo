#include <iostream>
#include <cstdio>
#include <string.h>
#include <malloc.h>
using namespace std;
#define  N 2000009

typedef struct queue
{
    int lenth[N];
    int head;
    int rear;
} que;
que *line;
int s[N];
que *initQueue()
{
    line = (que *)malloc(sizeof(que));
    line->head = line->rear = 0;
    memset(line->lenth,0,sizeof(line->lenth));
    return line;
}
void queueAdd(que *L,int x)
{
    L->lenth[L->rear] = x;
    L->rear++;
}
void queueDelete(que *L)
{
    printf("%d\n",L->lenth[L->head]);
    L->head++;
}

void findMax(que *L)
{
    int tmp;
    tmp = L->lenth[L->head];
    for(int i = L->head;i<L->rear;i++)
    {
        if(tmp < L->lenth[i])
            tmp = L->lenth[i];
    }
    printf("%d\n",tmp);
}
//Ê¹ÓÃ²åÈëÅÅÐò
//void insertSort(que *L,int x)
//{
//    int i,j;
//    for(i = L->rear;i<L->head;i++)
//    {
//        if(x)
//    }
//}
int main()
{
    int n;
    int a;
    char c;
    scanf("%d",&n);
    initQueue();
    for(int i=0;i<n;i++)
    {
        getchar();
        c = getchar();
        if(c=='E')
        {
            scanf("%d",&a);
            queueAdd(line,a);
        }
        if(c=='D')
            queueDelete(line);
        if(c=='M')
            findMax(line);
    }
    return 0;
}
