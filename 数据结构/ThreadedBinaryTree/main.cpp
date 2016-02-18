#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct BiThrNode
{
    int data;
    struct BiThrNode *lchild,*rchild;
    bool LTag;   ///LTag == 0 ,��ʾlchildָ�����ӣ�LTag==1����ʾlchildָ���Һ��ӣ�
    bool RTag;
}BiThrNode, *BiThrTree;

///��������������ĵݹ麯������
BiThrTree pre;   ///ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(p->lchild==NULL)///���û�����ӣ��ͽ�������������������ǰ�����
        {
            p->LTag=1;
            p->lchild = pre;
        }
        if(pre!=NULL&&pre->rchild==NULL)
        {
            pre->RTag = 1;
            pre->rchild=p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
