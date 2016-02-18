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
//初始化链栈
LinkStack *initLinkStack()
{
    return NULL;
}
//判断是否为空
int emptyLinkStack(LinkStack *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
        return 0;
}
//入栈
/** 这个是链栈 **/
LinkStack *pushLinkStack(LinkStack *top,DataType x)
{
    LinkStack *s;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    s->data = x;
    s->next = top;
    top = s;
    return top;
}
//出栈
LinkStack *popLinkStack(LinkStack *top)
{
    LinkStack *p;
    p = top;
    top = top->next;
    free(p);
    return top;
}
//读取栈顶元素
DataType topLinkStack (LinkStack *top)
{
    return top->data;
}
