#include <iostream>
#include <cstdio>
//#include <vector>
using namespace std;
#define N 100
void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex);
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex);
int binSearch(int Array[],int startIndex,int endIndex,int key);
int a[N],b[N];
int main()
{
    int n;
    int left;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
        MergeSort(a,b,0,n);
    for(int j=1; j<=n; j++)
    {
        printf("%d ",b[j]);
    }
    while(1)
    {
    scanf("%d",&left);
    cout<<binSearch(b,1,n,left)<<endl;
    cout<<"====="<<endl;
    }

    return 0;
}
/** 二路归并排序算法时间复杂度为：O（nlogn）
    速度比肩Qsort，相对于快排的优势：是稳定排序，而且任何情况下时间复杂度为O（nlogn）；
    排序结果降序排列
 **/
//MergSort内部调用merge方法进行排序
void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
{
    int midIndex;
    if(startIndex<endIndex)
    {
        midIndex=(startIndex+endIndex)/2;
        MergeSort(sourceArr,tempArr,startIndex,midIndex);
        MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
        Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
    }
}
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex,j=midIndex+1,k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i]<=sourceArr[j])
            tempArr[k++] = sourceArr[i++];
        else
            tempArr[k++] = sourceArr[j++];
    }
    while(i!=midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j!=endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

int binSearch(int Array[],int startIndex,int endIndex,int key)
{
    int left,right;
    int mid;
    left=startIndex;
    right=endIndex;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(key==Array[mid])
        {
                return mid;
        }
        else if(key<Array[mid])
        {
            right=mid-1;
        }
        else if(key>Array[mid])
        {
            left=mid+1;
        }
    }
            return -1;
}
