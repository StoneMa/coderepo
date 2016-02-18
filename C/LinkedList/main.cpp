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
LinkList *L = (LinkList *)malloc(sizeof(LinkList));
//建立带头结点的单链表
LinkList *createHeadList()
{
    LinkList *s;
    int x;
    scanf("%d",&x);
    while(x!=-1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));//新开一个LinkList类型指针；
        s->data = x;//这里先把该指针的数据域赋值；
        s->next = L->next;//将新开指针的指针域指向头结点；
        L->next= s;//将链表的头节点 的指针L->指向新开指针，注意这个L是指针名，应该一直位于首部，头插法的话，一直指向最新的节点。
        scanf("%d",&x);
    }
    return L;//返回头指针；
}
void showList(LinkList *L)
{
    LinkList *findL = L;
    while(findL->next!=NULL)
    {
        cout<<findL->next->data<<" ";
        findL = findL->next;
    }
        cout<<"end"<<endl;
}
//显示链表的当前长度
int showLength(LinkList *L)
{
    LinkList *p = L->next;
    int j=0;//计数
    while(p)
    {
        j++;
        p = p->next;
    }
    return j;
}
//插入新节点
LinkList *insertNode(LinkList *L, int i,DataType x)
{
    if(i<1||i>showLength(L)+1)
    {
        cout<<"插入位置错误"<<endl;
        return L;
    }
    LinkList *p,*s;
    int j=0;
    p = L;
    while(j<i-1)
    {
        p = p->next;
        j=j+1;
    }
    s = (LinkList *)malloc(sizeof(LinkList));
    s->data = x;
    //为什么这样不能在头部插入节点呢？
    // s->next = p;
    //L = s;
    /*这里注意p->next 其实是和L->next是同一个地址空间，
    所以修改p->next实际上就修改了L->next。所以当插到第一个位置的时候
    还是能将节点插入到整个链表当中，并使得L仍然是头节点的头指针。
    */
    s->next = p->next;
    p->next = s;
    return L;
}
//删除某个结点
 void deleteNode(LinkList *(&L),int i)
{
    LinkList *p,*q;
    int j = 0;
    p = L;
    while((p->next)&&(j<i-1))
    {
        p = p->next;
        j++;
    }
    if((!p->next)||(j>i-1))
    {
        printf("error"); return ;
    }
    q = p->next;
    p->next = q->next;
}
//修改某个结点的元素
void ModifyNode(LinkList *(&L),int i,DataType x)
{
    LinkList *p=L;
    int j=0;
    while((p->next)&&(j<i-1))
    {
        p = p->next;
        j++;
    }
    p->next->data = x;
}
//查询某个位置结点的元素；
void getNode(LinkList *(&L),int i)
{
    LinkList *p = L;
    int j = 0;
    while((p->next)&&(j<i-1))
    {
        p = p->next;
        j++;
    }
    printf("%d\n",p->next->data);
}
int main()
{
    L->next = NULL;
    int i,x;
    createHeadList();
    showList(L);
    //计算链表长度：
    cout<<"该链表长度为：";
    cout<<showLength(L)<<endl;
    cout<<"输入想要插入节点的位置及元素："<<endl;
    scanf("%d%d",&i,&x);
    insertNode(L,i,x);
    cout<<endl;
    showList(L);
    cout<<endl;
    cin>>x;
    deleteNode(L,x);
    showList(L);
    cin>>i>>x;
    ModifyNode(L,i,x);
    showList(L);
    cin>>i;
    getNode(L,i);
    showList(L);
    return 0;
}
