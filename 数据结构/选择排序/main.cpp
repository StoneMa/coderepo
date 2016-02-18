/*
* author：Yingshi.Ma
*   description：选择查找，数组样例
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
    int flag = 1;//这里一开始犯了错，注意要给flag赋初值，因为，并不是每次循环都能进入if语句，如果未进入，flag相当于野指针。
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
