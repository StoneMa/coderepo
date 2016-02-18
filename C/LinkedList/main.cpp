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
//������ͷ���ĵ�����
LinkList *createHeadList()
{
    LinkList *s;
    int x;
    scanf("%d",&x);
    while(x!=-1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));//�¿�һ��LinkList����ָ�룻
        s->data = x;//�����ȰѸ�ָ���������ֵ��
        s->next = L->next;//���¿�ָ���ָ����ָ��ͷ��㣻
        L->next= s;//�������ͷ�ڵ� ��ָ��L->ָ���¿�ָ�룬ע�����L��ָ������Ӧ��һֱλ���ײ���ͷ�巨�Ļ���һֱָ�����µĽڵ㡣
        scanf("%d",&x);
    }
    return L;//����ͷָ�룻
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
//��ʾ����ĵ�ǰ����
int showLength(LinkList *L)
{
    LinkList *p = L->next;
    int j=0;//����
    while(p)
    {
        j++;
        p = p->next;
    }
    return j;
}
//�����½ڵ�
LinkList *insertNode(LinkList *L, int i,DataType x)
{
    if(i<1||i>showLength(L)+1)
    {
        cout<<"����λ�ô���"<<endl;
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
    //Ϊʲô����������ͷ������ڵ��أ�
    // s->next = p;
    //L = s;
    /*����ע��p->next ��ʵ�Ǻ�L->next��ͬһ����ַ�ռ䣬
    �����޸�p->nextʵ���Ͼ��޸���L->next�����Ե��嵽��һ��λ�õ�ʱ��
    �����ܽ��ڵ���뵽���������У���ʹ��L��Ȼ��ͷ�ڵ��ͷָ�롣
    */
    s->next = p->next;
    p->next = s;
    return L;
}
//ɾ��ĳ�����
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
//�޸�ĳ������Ԫ��
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
//��ѯĳ��λ�ý���Ԫ�أ�
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
    //���������ȣ�
    cout<<"��������Ϊ��";
    cout<<showLength(L)<<endl;
    cout<<"������Ҫ����ڵ��λ�ü�Ԫ�أ�"<<endl;
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
