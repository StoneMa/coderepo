#include <stdio.h>
#include <cstring>
using namespace std;
#define MAX 1600009
int Stack[MAX];
int a[MAX];
int top=0;	//栈顶指针

int main()
{
    int n,m;
    int i;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);

    //第一遍先将所有数据录入栈中，不要输出，用于查找所有不符合要求的样例
    int j=0;
    for(i=1; i<=n; i++)
    {
        if(a[i]<Stack[top])
        {
            /**
            这里第一遍的循环的时候top()栈中为赋值，
            下面的while循环中给栈中元素进行了赋值如果；
            如果结果不符合要求，直接打印no；
            **/
            printf("No\n");
            return 0;
        }
        //直到 a[i] 的元素全部加入栈
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
//这次循环用于输出复符合要求的情况是如何操作的
    top=0;
    j=0;
    for(i=1; i<=n; i++)
    {
        //直到 a[i] 的元素全部加入栈
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
