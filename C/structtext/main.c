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
//λ�ü��
int checkLocation(seqList *L,int i)
{
    if(i>L->last+1||i<1)
    {
        return 0;
    }
    else
        return 1;
}
//˳���Ĳ��룻
int insertElem(seqList *L, int i, dataType element)
{
    if(checkLocation(L,i))
    {
        for(j=L->last;j>=i-1;j--)//����ط��Ӵ�СҪ�ȴ�С���󷽱㣬��Ϊ����ֱ�ӽ�����ֵ����Ųһ��λ�ã������ÿ��Ǻ��߱����ǣ�
        {
            L->data[j+1] = L->data[j];
        }
        L->data[i-1] = element;
        L->last++;
    }
    else
        printf("λ�ô���,����ʧ��\n");

    return 1;
}
//��ʾ����˳���
void showList(seqList *L)
{
    printf("˳����ڵ�Ԫ��Ϊ��\n");
    for(j=0;j<L->last;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n");
}
//��ʾ˳�����ĳ��Ԫ��
void showOneElem(seqList *L,int i)
{
    if(checkLocation(L,i))
    printf("%d\n",L->data[i-1]);
}
//��ʼ��˳���
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
    printf("�������\n");
}
//ɾ��ĳλ�õ�Ԫ��
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
            printf("λ�ô���ɾ��ʧ��\n");

    return 1;
}

seqList list;
int main()
{
    initList(&list);
    printf("�س�����ʾȫ��Ԫ��:\n");
    getchar();getchar();
    showList(&list);
    printf("�ڶ�Ӧλ�ò���Ԫ��,�������Ӧ��λ��i���Լ���Ҫ�����Ԫ��x��\n");
    scanf("%d",&i);
    scanf("%d",&x);
    insertElem(&list,i,x);
    showList(&list);
    printf("��ʱ�ĳ���Ϊ:%d\n",list.last);
    showOneElem(&list,i);
    deleteElem(&list,i);
    showList(&list);
    return 0;
}

