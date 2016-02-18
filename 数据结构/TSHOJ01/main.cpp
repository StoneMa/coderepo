#include <iostream>
#include <cstdio>
using namespace std;

int a[500010];
int b[500010];

void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex);
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex);
//二分查找，左侧位置和右侧位置分开查找
//对于左侧位置，如果没有hit对象，返回该位置的左侧元素的角标
int find_left(int l,int r, int v) {

    if (l == r) {
       return l;
    }
    int mid = (l+r)/2;
    if (a[mid] < v) {
       return find_left(mid+1,r,v);
    }
    else {
        return find_left(l,mid,v);
    }
}
//对于右侧位置，如果没有hit对象，返回该位置的右侧元素的角标
int find_right(int l,int r,int v) {
    if (l == r) {
       return l;
    }
    int mid = (l+r+1)/2;
    if (a[mid] > v) {
       return find_right(l,mid-1,v);
    }
    else {
         return find_right(mid,r,v);
    }
}

void swap(int& a,int& b) {
     int t = a;
     a = b;
     b = t;
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
     MergeSort(a,b,0,n-1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) {
           swap(l,r);
        }
        if (l > a[n-1] || r < a[0]) {
           printf("0\n");
        }
        else {
             printf("%d\n",find_right(0,n-1,r)-find_left(0,n-1,l)+1);
        }
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

