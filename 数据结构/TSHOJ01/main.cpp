#include <iostream>
#include <cstdio>
using namespace std;

int a[500010];
int b[500010];

void MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex);
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex);
//���ֲ��ң����λ�ú��Ҳ�λ�÷ֿ�����
//�������λ�ã����û��hit���󣬷��ظ�λ�õ����Ԫ�صĽǱ�
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
//�����Ҳ�λ�ã����û��hit���󣬷��ظ�λ�õ��Ҳ�Ԫ�صĽǱ�
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
/** ��·�鲢�����㷨ʱ�临�Ӷ�Ϊ��O��nlogn��
    �ٶȱȼ�Qsort������ڿ��ŵ����ƣ����ȶ����򣬶����κ������ʱ�临�Ӷ�ΪO��nlogn����
    ��������������
 **/
//MergSort�ڲ�����merge������������
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

