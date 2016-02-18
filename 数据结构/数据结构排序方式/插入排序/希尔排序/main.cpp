/**　
希尔排序
关键思想：确定步长，以及排序次数，确定好边界条件
**/
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
int n;
//一次希尔排序过程。
//自己写的排序函数
void shellInsertSort(int a[],int d)//数组a，数组元素数量n，步长d
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
书本上给出的排序函数
void shellInsertSort(int a[],int d)//数组a，数组元素数量n，步长d
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
// k来控制排序趟数；d[i]为每趟排序的步长；最后一次迭代步长一定为1；
void shellSort(int a[],int d[],int t)
{
    for(int k =0;k<t;k++)   shellInsertSort(a,d[k]);
}


int main()
{
    printf("**********希尔排序***********\n");
    int a[N];
    int d[3]={5,3,1};
    cout<<"输入要排序的数的个数:"<<endl;
    scanf("%d",&n);
    cout<<"输入"<<n<<"个数，以空格隔开:"<<endl;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    shellSort(a,d,3);
    for(int i=1;i<=n;i++)
        printf("%d  ",a[i]);
    return 0;
}
