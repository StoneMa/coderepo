/*˳��ջ
    ˳��ջ�Ĵ洢��ʽ�����飻����ջ�Ĵ洢��ʽ��������ͨ���ǵ�����
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
    int top;//��Զָ��ջ��Ԫ�أ��������������Ԫ�صĽǱ꣬��Ȼ�С�ջ��ָ�롱��������˳��ջ��top���ǽǱ�int�ͣ�
}seqStack ;
//��ʼ��˳��ջ
seqStack *initSeqStack()
{
    seqStack *s;
    s = (seqStack *)malloc(sizeof(seqStack));
    s->top = -1;//��ʾջΪ�գ����������ջ�������Ͳ������磻
    //ÿ����Ԫ����ջʱ������ջ��ָ��+1��Ҳ����top++������top�������Ϊ�µ�ջ��Ԫ�صĽǱꣻ
    return s;
}
//�жϿ�ջ
int emptyStack(seqStack *s)
{
    if(s->top==-1)//���ջ��ָ���ֵ�ǳ�ʼ��ʱ��-1���Ǿͱ�ʾջΪ��
    {
        return 1;//���ʾ�ǿ�ջ
    }
    else
    {
        return 0;//�ٱ�ʾ�ǿ�ջ��
    }
}
//��ջ����
int push(seqStack *s,DataType x)
{
    if(s->top==MAXSIZE-1)//MAXSIZE-1��ʾ�������Ԫ�صĽǱ꣬�������ж�ջ�Ƿ�������
    {
        cout<<"ջ����"<<endl;
        return 0;// 0 ��ʾ��ջʧ�ܣ�
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;//��ʾ��ջ�ɹ���
    }
}
//��ջ����ʵ��û��������ɾ��Ԫ�أ�ֻ�ǵ���topָ���λ�ã�
void pop(seqStack *s)
{
    s->top--;
}
//��ȡջ��Ԫ��
DataType top(seqStack *s)
{
    return (s->data[s->top]);
}
/** ����ջ��ջ���Կ��� ����ջ��ջ���������൱�����Ա�ı�β���в����ɾ������ **/
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
        if(i==-1)//i��ֵΪ-1��ʱ������
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

