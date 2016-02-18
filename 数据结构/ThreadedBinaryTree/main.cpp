#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct BiThrNode
{
    int data;
    struct BiThrNode *lchild,*rchild;
    bool LTag;   ///LTag == 0 ,表示lchild指向左孩子，LTag==1，表示lchild指向右孩子；
    bool RTag;
}BiThrNode, *BiThrTree;

///中序遍历线索化的递归函数代码
BiThrTree pre;   ///全局变量，始终指向刚刚访问过的结点
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(p->lchild==NULL)///如果没有左孩子，就进行线索化，设置它的前驱结点
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
