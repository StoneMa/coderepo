/*
* author��Yingshi.Ma
*   description��ѡ����ң���������
*/

#include <iostream>
#include <cstdio>
using namespace std;
typedef int dataType;

void selectionSort(int a[],int n);
int main()
{
    dataType a[1000];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    selectionSort(a,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d   ",a[i]);
    }
    return 0;
}

void selectionSort(int a[],int n)
{
    if(n == 1)
        return;
    else
    {
            a[0] = a[1];
    int flag = 1;//����һ��ʼ���˴�ע��Ҫ��flag����ֵ����Ϊ��������ÿ��ѭ�����ܽ���if��䣬���δ���룬flag�൱��Ұָ�롣
    for(int i=2; i<=n; i++)
    {
        if(a[0]<=a[i])
            {
                  a[0] = a[i];
                  flag = i;
            }
    }
        a[flag] = a[n];
        a[n] = a[0];
        selectionSort(a,n-1);
    }
}
