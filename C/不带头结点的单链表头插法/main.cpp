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

//��ʾ����ĵ�ǰ����
int showLength(LinkList *L)
{
    LinkList *p = L;
    int j=0;//����
    while(p)
    {
        j++;
        p = p->next;
    }
    return j;
}
//��������ͷ���ĵ�����
LinkList *createHeadList()
{
    LinkList *s;
    int x;
    scanf("%d",&x);
    while(x!=-1)
    {
        s = (LinkList *)malloc(sizeof(LinkList));//�¿�һ��LinkList����ָ�룻
        s->data = x;//�����ȰѸ�ָ���������ֵ��
        s->next = L;//���¿�ָ���ָ����ָ��ͷָ��ָ��Ľڵ㣻
        L= s;//������ĵ�һ���ڵ��ָ��Lָ���¿�ָ�룬ע�����L��ָ������Ӧ��һֱλ���ײ���ͷ�巨�Ļ���һֱָ�����µĽڵ㡣
        scanf("%d",&x);
    }
    return L;//����ͷָ�룻
}
//��ӡ��������
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
//�����½ڵ�
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
    if(i==1)//��������λ���ǵ�һ���������һ������Ҫ�������⴦��
    {
        s->next = L;
        L = s;
    }
    else if(i==showLength(L)+1)//��������һ��λ��
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
//ɾ��ĳ�����
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
    //���������ȣ�
    cout<<"��������Ϊ��";
    cout<<showLength(L)<<endl;
    cout<<"������Ҫ����ڵ��λ�ü�Ԫ�أ�"<<endl;
    scanf("%d%d",&i,&x);
    L = insertNode(L,i,x);
    cout<<endl;
    showList(L);
    return 0;
}
