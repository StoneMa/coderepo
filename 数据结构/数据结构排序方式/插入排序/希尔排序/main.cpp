/**��
ϣ������
�ؼ�˼�룺ȷ���������Լ����������ȷ���ñ߽�����
**/
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
int n;
//һ��ϣ��������̡�
//�Լ�д��������
void shellInsertSort(int a[],int d)//����a������Ԫ������n������d
{
    int i,j;
    for(i =1;i+d<=n;i++)
    {
        a[0] = a[i];
        j = i+d;
        while(j<=n&&a[j]<a[0])
        {
            a[j-d] = a[j];
            a[j] = a[0];
             j = j+d;
        }

    }
}
/**
�鱾�ϸ�����������
void shellInsertSort(int a[],int d)//����a������Ԫ������n������d
{
    int i,j;
    for(i =1+d;i<=n;i++)
    {
        a[0] = a[i];
        j = i-d;
        while(j>0&&a[j]>a[0])
        {
            a[j+d] = a[j];
             j = j-d;
        }
        a[j+d] = a[0];
    }
}
**/
// k����������������d[i]Ϊÿ������Ĳ��������һ�ε�������һ��Ϊ1��
void shellSort(int a[],int d[],int t)
{
    for(int k =0;k<t;k++)   shellInsertSort(a,d[k]);
}


int main()
{
    printf("**********ϣ������***********\n");
    int a[N];
    int d[3]={5,3,1};
    cout<<"����Ҫ��������ĸ���:"<<endl;
    scanf("%d",&n);
    cout<<"����"<<n<<"�������Կո����:"<<endl;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    shellSort(a,d,3);
    for(int i=1;i<=n;i++)
        printf("%d  ",a[i]);
    return 0;
}
