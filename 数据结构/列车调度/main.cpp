#include <stdio.h>
#include <cstring>
using namespace std;
#define MAX 1600009
int Stack[MAX];
int a[MAX];
int top=0;	//ջ��ָ��

int main()
{
    int n,m;
    int i;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);

    //��һ���Ƚ���������¼��ջ�У���Ҫ��������ڲ������в�����Ҫ�������
    int j=0;
    for(i=1; i<=n; i++)
    {
        if(a[i]<Stack[top])
        {
            /**
            �����һ���ѭ����ʱ��top()ջ��Ϊ��ֵ��
            �����whileѭ���и�ջ��Ԫ�ؽ����˸�ֵ�����
            ������������Ҫ��ֱ�Ӵ�ӡno��
            **/
            printf("No\n");
            return 0;
        }
        //ֱ�� a[i] ��Ԫ��ȫ������ջ
        if(j<a[i])
            while(j!=a[i])
            {
                Stack[++top]=++j;
                if(top>m)
                {
                    printf("No\n");
                    return 0;
                }
            }
        if(a[i]==Stack[top])
            top--;
    }
//���ѭ���������������Ҫ����������β�����
    top=0;
    j=0;
    for(i=1; i<=n; i++)
    {
        //ֱ�� a[i] ��Ԫ��ȫ������ջ
        if(j<a[i])
            while(j!=a[i])
            {
                Stack[++top]=++j;
                printf("push\n");
            }
        if(a[i]==Stack[top])
            {
                    top--;
                    printf("pop\n");
            }
    }

    return 0;
}
