#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
}LinkList ;

LinkList *L;

//显示链表的当前长度
int showLength(LinkList *L)
{
    LinkList *p = L;
    int j=0;//计数
    while(p)
    {
        j++;
        p = p->next;
    }
    return j;
}
//建立不带头结点的单链表
LinkList *createHeadList()
{
    LinkList *s;
    int x;
    scanf("%d",&x);
    while(x!=-1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));//新开一个LinkList类型指针；
        s->data = x;//这里先把该指针的数据域赋值；
        s->next = L;//将新开指针的指针域指向头指针指向的节点；
        L= s;//将链表的第一个节点的指针L指向新开指针，注意这个L是指针名，应该一直位于首部，头插法的话，一直指向最新的节点。
        scanf("%d",&x);
    }
    return L;//返回头指针；
}
//打印出链表长度
void showList(LinkList *L)
{
    LinkList *findL = L;
    while(findL!=NULL)
    {
        cout<<findL->data<<" ";
        findL = findL->next;
    }
        cout<<endl;
}
//插入新节点
LinkList *insertNode(LinkList *L, int i,DataType x)
{
    LinkList *p,*s;
    int j=1;
    p = L;
    while(j<i-1)
    {
        p = p->next;
        j=j+1;
    }
    s = (LinkList *)malloc(sizeof(LinkList));
    s->data = x;
    if(i==1)//如果插入的位置是第一个或者最后一个，都要进行特殊处理
    {
        s->next = L;
        L = s;
    }
    else if(i==showLength(L)+1)//如果是最后一个位置
    {
        s->next = NULL;
        p->next = s;
    }
    else
    {
        s->next = p->next;
        p->next = s;
    }
    return L;
}
//删除某个结点
 void deleteNode(LinkList *(&L),int i)
{
    int j=0;

}
int main()
{
    L = NULL;
    int i,x;
    createHeadList();
    showList(L);
    //计算链表长度：
    cout<<"该链表长度为：";
    cout<<showLength(L)<<endl;
    cout<<"输入想要插入节点的位置及元素："<<endl;
    scanf("%d%d",&i,&x);
    L = insertNode(L,i,x);
    cout<<endl;
    showList(L);
    return 0;
}
