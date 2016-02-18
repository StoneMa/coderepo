#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int dataType;
int i,j;
dataType x;
typedef struct
{
    dataType data[100];
    int last;
} seqList;
//位置检查
int checkLocation(seqList *L,int i)
{
    if(i>L->last+1||i<1)
    {
        return 0;
    }
    else
        return 1;
}
//顺序表的插入；
int insertElem(seqList *L, int i, dataType element)
{
    if(checkLocation(L,i))
    {
        for(j=L->last;j>=i-1;j--)//这个地方从大到小要比从小到大方便，因为可以直接将最后的值往后挪一个位置，而不用考虑后者被覆盖；
        {
            L->data[j+1] = L->data[j];
        }
        L->data[i-1] = element;
        L->last++;
    }
    else
        printf("位置错误,插入失败\n");

    return 1;
}
//显示整个顺序表
void showList(seqList *L)
{
    printf("顺序表内的元素为：\n");
    for(j=0;j<L->last;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n");
}
//显示顺序表内某个元素
void showOneElem(seqList *L,int i)
{
    if(checkLocation(L,i))
    printf("%d\n",L->data[i-1]);
}
//初始化顺序表
void initList(seqList *L)
{
    L->last = 0;
    memset(L->data,0,sizeof(L->data));
    printf("insert data ,when u give '-1' over it\n");
    while(scanf("%d",&L->data[L->last]))
    {
        if(L->data[L->last] == -1)
        {
            break;
        }
        else
            L->last++;
    }
    printf("输入结束\n");
}
//删除某位置的元素
int deleteElem(seqList *L, int i)
{
        if(checkLocation(L,i))
        {
            for(j=i;j<L->last;j++)
            {
                L->data[j-1] = L->data[j];
            }
                L->last--;
        }
        else
            printf("位置错误，删除失败\n");

    return 1;
}

seqList list;
int main()
{
    initList(&list);
    printf("回车后显示全部元素:\n");
    getchar();getchar();
    showList(&list);
    printf("在对应位置插入元素,请输入对应的位置i，以及想要插入的元素x：\n");
    scanf("%d",&i);
    scanf("%d",&x);
    insertElem(&list,i,x);
    showList(&list);
    printf("此时的长度为:%d\n",list.last);
    showOneElem(&list,i);
    deleteElem(&list,i);
    showList(&list);
    return 0;
}

