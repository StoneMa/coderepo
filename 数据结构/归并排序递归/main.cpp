///*递归归并排序
// *将有二个有序数列list[first...mid]和list[mid+1,...last]合并
// *list:待排序数组
// *first:子序列1的下界
// *mid:子序列1的上界
// *last:子序列2的上界
// *temp:临时保存数组
//*/
//void Merge(element list[], int first, int mid, int last, element temp[])
//{
//    int i = first, j = mid + 1;
//    int m = mid,   n = last;
//    int k = 0;
//
//    while (i <= m && j <= n)
//    {
//        if (list[i] < list[j])
//            temp[k++] = list[i++];
//        else
//            temp[k++] = list[j++];
//    }
//
//    while (i <= m)
//        temp[k++] = list[i++];
//
//    while (j <= n)
//        temp[k++] = list[j++];
//
//    for (i = 0; i < k; i++)
//        list[first + i] = temp[i];
//
//    return ;
//}
///*递归归并排序
// *分治，完成递归归并
// *list：待排序数组
// *first:list下界
// *last:list上界
// *temp:临时保存数组
//*/
//void mergesort(element list[], int first, int last, element temp[])
//{
//    if (first < last)
//    {
//        int mid = (first + last) / 2;
//        mergesort(list, first, mid, temp);    //左边有序
//        mergesort(list, mid + 1, last, temp); //右边有序
//        Merge(list, first, mid, last, temp); //再将二个有序数列合并
//    }
//    return ;
//}
///*递归归并排序
// *list：待排序数组
// *n:为数组长度
//*/
//bool MergeSort(element list[], int n)
//{
//    element *p = new element[n];//空间复杂度为O(n)
//    if (p == NULL)
//        exit(1);
//
//    mergesort(list, 0, n - 1, p);
//
//    delete[] p;
//    return true;
//}
#include <iostream>
#include <cstdio>
#define N 100
using namespace std;
int arr[N];
int  b[N];
void MergeSort(int low,int high)
{
    int mid;
    if(low>=high)
        return;//每个子列表中剩下一个元素时停止
    else
        mid=(low+high)/2;
    MergeSort(low,mid);//子列表进一步划分
    MergeSort(mid+1,high);

    //新建一个数组，用于存放归并的元素

    for(int i=low,j=mid+1,k=low; i<=mid && j<=high; k++)
    {
        if (arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
    }
    for( int j = 0,k=0;j<=high; j++,k++) //如果第二个子列表中仍然有元素，则追加到新列表
        b[k]=arr[j];
    for( int i=0,k=0;i<=mid; i++,k++) //如果在第一个子列表中仍然有元素，则追加到新列表中
        b[k]=arr[i];
    for(int z=0; z<high-low+1; z++) //将排序的数组B的 所有元素复制到原始数组arr中
        arr[z]=b[z];
}


int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    MergeSort(0,n);
    for(int j=0; j<n; j++)
    {
        printf("%d ",b[j]);
    }
    printf("\n");
    return 0;
}
