/* 这里编写树的三种遍历方式 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
using namespace std;
typedef int TElemType;
//树结构
typedef struct BiTNode /** 结点结构 **/
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

        /** 先序遍历算法 **/
void PreOrderTraverse(BiTree T)
{
        if(T==NULL)
            return;
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
}
/********************************/

        /** 中序遍历算法 **/
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}
/********************************/

        /** 后序遍历算法 **/
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf(T->data);
}


//**********************************//
/*
    递归查找二叉排序树T中是否存在key，
    指针 f 指向T的双亲节点，初始值为null；
    若查找成功，指针p指向该数据元素结点，并返回TRUE；
    若查找失败，指针p指向查找路径上访问的最后一个结点并返回false；
*/
/** 二叉排序树的查找操作 **/
Status SearchBST(BiTree T, int key , BiTree f, BiTree *p)
{
    if(!T) //当前树为空，查找不成功//
    {
        *p  = f;
        return false;
    }
    else if (key==T->data) //当前结点值刚好匹配，查找成功//
    {
        *p = T;
        return true;
    }
    else if(key<T->data)  /// 如果目标key小于当前结点的data值，继续在当前结点的左子树进行查找；
        return SearchBST(T->lchild,key,T,p);
    else                            /// 如果目标key大于当前结点的data值，继续在当前结点的右子树进行查找；
        return SearchBST(T->rchild,key,T,p);
}


/*
    当二叉排序树T中不存在关键字等于key的数据元素时，
    插入key并返回TRUE，否则返回False；
*/
Status InsertBST(BiTree *T,int key)
{
    BiTree p,s;
    if( ! SearchBST(*T, key, NULL, &p) )  /**先判断当前树中是否存在要插入的元素，若不存在，则进行如下操作 **/
        {
            s= (BiTree) malloc (sizeof(BiTree)); //为新插入结点开辟空间；
            s->data = key;         //给新开结点的数据域赋值；
            s->lchild = s->rchild = NULL;  //置新结点的指针域为空；
            if (!p) /** 这里的p指向SearchBST的查找结果，如果查找失败，那么p的值为false **/
                *T = s;   /** 这一行代码只是单纯的去考虑如果这个树一开始就是空树的情况，这时候 s 结点直接构成根节点**/
            else if(key<p->data)
                p->lchild = s;
            else
                p->rchild = s;
            return true;
        }
    else
        return false; ///树中已有与该关键字相同的结点，不进行插入
}
