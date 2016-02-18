/*顺序栈
    顺序栈的存储方式是数组；而链栈的存储方式是链表；（通常是单链表）
*/
#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define MAXSIZE 1024
typedef int DataType;
typedef struct
{
    DataType data[MAXSIZE];
    int top;//永远指向栈顶元素；在这里就是数组元素的角标，虽然叫“栈顶指针”，但是在顺序栈中top就是角标int型；
}seqStack ;
//初始化顺序栈
seqStack *initSeqStack()
{
    seqStack *s;
    s = (seqStack *)malloc(sizeof(seqStack));
    s->top = -1;//表示栈为空；如果再做出栈操作，就产生下溢；
    //每次有元素入栈时，先让栈顶指针+1；也就是top++；这样top便可以作为新的栈顶元素的角标；
    return s;
}
//判断空栈
int emptyStack(seqStack *s)
{
    if(s->top==-1)//如果栈顶指针的值是初始化时的-1，那就表示栈为空
    {
        return 1;//真表示是空栈
    }
    else
    {
        return 0;//假表示非空栈；
    }
}
//入栈操作
int push(seqStack *s,DataType x)
{
    if(s->top==MAXSIZE-1)//MAXSIZE-1表示最大数组元素的角标，这样来判断栈是否已满；
    {
        cout<<"栈已满"<<endl;
        return 0;// 0 表示入栈失败；
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;//表示入栈成功；
    }
}
//出栈，其实并没有真正的删除元素，只是调整top指针的位置；
void pop(seqStack *s)
{
    s->top--;
}
//读取栈顶元素
DataType top(seqStack *s)
{
    return (s->data[s->top]);
}
/** 从入栈出栈可以看出 ，入栈出栈操作就是相当于线性表的表尾进行插入和删除操作 **/
int main()
{
    seqStack *s;
    int x,n;
    cout<<"how many element do u want the stack have ?"<<endl;
    cin>>n;
    s = initSeqStack();
    cout<<"insert new element:"<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==-1)//i赋值为-1的时候跳出
            break;
        cin>>x;
        push(s,x);
    }
    cout<<"the top element is:"<<top(s)<<endl;
    cout<<"the num of element is :"<<s->top+1<<endl;
    cout<<"after a pop:"<<endl;
    pop(s);
    cout<<"the num of element is :"<<s->top+1<<endl;
    cout<<"the top element is"<<top(s)<<endl;
    return 0;
}

