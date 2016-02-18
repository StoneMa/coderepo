/**
 简单直接插入排序
注意事项：从后向前比较
第 i 个数据先和i-1个数据比较，如果小于第i-1个数据，再向前比较
时间复杂度，最好的情况下：O(n)；最坏的时间复杂度：O(n^2);
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
