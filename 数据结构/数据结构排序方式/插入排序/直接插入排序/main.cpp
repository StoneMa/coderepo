/**
 ��ֱ�Ӳ�������
ע������Ӻ���ǰ�Ƚ�
�� i �������Ⱥ�i-1�����ݱȽϣ����С�ڵ�i-1�����ݣ�����ǰ�Ƚ�
ʱ�临�Ӷȣ���õ�����£�O(n)�����ʱ�临�Ӷȣ�O(n^2);
 **/
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
void StraightInsertionSort(int a[],int n);
int main()
{
    int n;
    int a[N];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    StraightInsertionSort(a,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}

void StraightInsertionSort(int a[],int n)
{
    int i,j;
    for( i=2;i<=n;i++)
    {
        a[0] = a[i];
        j = i-1;
        while(a[0]<a[j])
        {
            a[j+1] = a[j];
            j--;
            a[j+1] = a[0];
        }
    }
}
