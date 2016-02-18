/* �����д�������ֱ�����ʽ */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
using namespace std;
typedef int TElemType;
//���ṹ
typedef struct BiTNode /** ���ṹ **/
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

        /** ��������㷨 **/
void PreOrderTraverse(BiTree T)
{
        if(T==NULL)
            return;
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
}
/********************************/

        /** ��������㷨 **/
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}
/********************************/

        /** ��������㷨 **/
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
    �ݹ���Ҷ���������T���Ƿ����key��
    ָ�� f ָ��T��˫�׽ڵ㣬��ʼֵΪnull��
    �����ҳɹ���ָ��pָ�������Ԫ�ؽ�㣬������TRUE��
    ������ʧ�ܣ�ָ��pָ�����·���Ϸ��ʵ����һ����㲢����false��
*/
/** �����������Ĳ��Ҳ��� **/
Status SearchBST(BiTree T, int key , BiTree f, BiTree *p)
{
    if(!T) //��ǰ��Ϊ�գ����Ҳ��ɹ�//
    {
        *p  = f;
        return false;
    }
    else if (key==T->data) //��ǰ���ֵ�պ�ƥ�䣬���ҳɹ�//
    {
        *p = T;
        return true;
    }
    else if(key<T->data)  /// ���Ŀ��keyС�ڵ�ǰ����dataֵ�������ڵ�ǰ�������������в��ң�
        return SearchBST(T->lchild,key,T,p);
    else                            /// ���Ŀ��key���ڵ�ǰ����dataֵ�������ڵ�ǰ�������������в��ң�
        return SearchBST(T->rchild,key,T,p);
}


/*
    ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ��
    ����key������TRUE�����򷵻�False��
*/
Status InsertBST(BiTree *T,int key)
{
    BiTree p,s;
    if( ! SearchBST(*T, key, NULL, &p) )  /**���жϵ�ǰ�����Ƿ����Ҫ�����Ԫ�أ��������ڣ���������²��� **/
        {
            s= (BiTree) malloc (sizeof(BiTree)); //Ϊ�²����㿪�ٿռ䣻
            s->data = key;         //���¿�����������ֵ��
            s->lchild = s->rchild = NULL;  //���½���ָ����Ϊ�գ�
            if (!p) /** �����pָ��SearchBST�Ĳ��ҽ�����������ʧ�ܣ���ôp��ֵΪfalse **/
                *T = s;   /** ��һ�д���ֻ�ǵ�����ȥ������������һ��ʼ���ǿ������������ʱ�� s ���ֱ�ӹ��ɸ��ڵ�**/
            else if(key<p->data)
                p->lchild = s;
            else
                p->rchild = s;
            return true;
        }
    else
        return false; ///����������ùؼ�����ͬ�Ľ�㣬�����в���
}
