#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
typedef int DataType;
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
typedef struct Node
{
    DataType data;
    struct Node *next;
}LinkStack;
LinkStack *top;
//��ʼ����ջ
LinkStack *initLinkStack()
{
    return NULL;
}
//�ж��Ƿ�Ϊ��
int emptyLinkStack(LinkStack *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
        return 0;
}
//��ջ
/** �������ջ **/
LinkStack *pushLinkStack(LinkStack *top,DataType x)
{
    LinkStack *s;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    s->data = x;
    s->next = top;
    top = s;
    return top;
}
//��ջ
LinkStack *popLinkStack(LinkStack *top)
{
    LinkStack *p;
    p = top;
    top = top->next;
    free(p);
    return top;
}
//��ȡջ��Ԫ��
DataType topLinkStack (LinkStack *top)
{
    return top->data;
}
