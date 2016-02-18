#include <iostream>
#include <malloc.h>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Node
{
    char c;
    struct Node *prior,*next;
}LinkList;

LinkList *L = (LinkList *)malloc(sizeof(LinkList));

LinkList *insertNode(LinkList*L,int i,char x)
{
    LinkList *s,*p;
    s = (LinkList *)malloc(sizeof(LinkList));
    s->c = x;
    p = L;
    if(i==0)
        {
            s->next = p->next;
            if(p->next)
                p->next->prior = s;
            p->next = s;
            s->prior = p;
            p = s;
        }
    if(i!=0)
    {
        while(i)
        {
            p = p->next;
            i--;
        }
            s->prior = p;
            s->next = p->next;
            if(p->next)
            p->next->prior = s;
            p->next = s;
            p = s;
    }
    return p;
}
int initList(LinkList *L)
{
    LinkList *s,*p;
    p=L;
    int num,flag;
    char a[10009];
    memset(a,0,sizeof(a));
    gets(a);
    num = strlen(a);
    flag = num;//统计一下初始字符的个数；
    for(int i=0;i<num;i++)
    {
        s = (LinkList*)malloc(sizeof(LinkList));
        s->c = a[i];
        s->prior = p;
        s->next = p->next;
        p->next = s;
        p = s;
    }
    return flag;
}
void checkList(LinkList *p,int i,int &n)
{
    while(L->next)
    {
        if(i>0&&i<n)
            {
                if((p->prior->c==p->c)&&(p->next->c==p->c))
                        {
                            p->prior->prior->next = p->next->next;
                            if(p->next->next)
                                p->next->next->prior = p->prior->prior;
                            p = p->prior->prior;
                            n = n-2;
                            i= i-1;
                            continue;
                        }
            }
        if(i!=n)
            {
                //至少三个节点才进行判断
                if(p->next&&p->next->next)
                {
                    if((p->c == p->next->c)&&(p->c == p->next->next->c))
                        {
                        p->next->next->next->prior = p->prior;
                        p->prior->next = p->next->next->next;
                        p = p->prior->next;
                        n = n-2;
                        continue;
                        }
                }
            }
        if(i!=0)
            {
                if(!(p->prior)||!(p->prior->prior))
                    break;
               else if((p->c==p->prior->c)&&(p->c == p->prior->prior->c))
                {
                    p->prior->prior->prior->next = p->next;
                    if(p->next)
                        p->next->prior = p->prior->prior->prior;
                    p = p->next->prior;
                    n = n-2;
                    i = i-2;
                    continue;
                }
            }
            n++;
        break;
    }
}
void listShow(LinkList *L)
{
    LinkList *p = L->next;
    if(p)
    {
            while(p)
            {
                printf("%c",p->c);
                p = p->next;
            }
    }
    else
        printf("-");
}
int main()
{
    L->next = NULL;
    L->prior = NULL;
    LinkList *point;
    int n;
    int i;
    char x;
    int num;
    num = initList(L);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&i);
        getchar();
        scanf("%c",&x);
        point = insertNode(L,i,x);
        checkList(point,i,num);
        if(n)
        {
            listShow(L);
            printf("\n");
        }
        else
            listShow(L);
    }
    return 0;
}
