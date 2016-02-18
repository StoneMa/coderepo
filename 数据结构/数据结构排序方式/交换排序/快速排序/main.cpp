/**
    快速排序
    关键思想：每次排序以第一个数组元素为比较数（当然实际情况也可以是最后一个数，但若是使用中间的数，操作搜索起来会比较繁琐）；
    依次：
    从最后一个位置向前搜索比对比数小的数；
    从最前一个位置向后搜索比对比数大的数；
    直到low和high相遇，此时  low = high，所以单次排序算法无所谓返回low还是high；
    此时low（或high）的位置就是当前对比数a[0]的最终位置；
    然后记录当前位置，利用二分的思想，将它前方和后方的元素进行相同的排序，直到全体有序；
 **/
 //每一遍快排都会确定一个数的最终位置；之后的排序过程中不会引发这个数的位置的改变；

#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
int partition(int a[],int low,int high)
{
    int k;
    a[0] = a[low];
    k = a[low];
        while(low<high)
        {
            while((low<high)&&a[high]>=k)
                high--;//从后向前查找，如果当前a[high]比a[0]中的值大，就继续向前搜索；
            /** 完成上面的while循环之后进入下面if语句 **/
            if(low<high)//若跳出循环的原因为：搜索到了比a[0]小的值；
                a[low] = a[high];//给当前对比基准位置的数组元素赋值，

            while((low<high)&&a[low]<=k)
                low++;//同一遍快排要进行从前向后搜索

                if(low<high)
                    a[high] = a[low];
        }
    a[low] = a[0];
    return low;
}
void Qsort(int a[],int low,int high)
{
    int part;
    if(low<high)
    {
        part = partition(a,low,high);
        Qsort(a,low,part-1);
        Qsort(a,part+1,high);
    }
}

int main()
{
    int a[N];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    Qsort(a,1,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
