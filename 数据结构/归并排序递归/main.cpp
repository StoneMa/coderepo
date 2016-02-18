///*�ݹ�鲢����
// *���ж�����������list[first...mid]��list[mid+1,...last]�ϲ�
// *list:����������
// *first:������1���½�
// *mid:������1���Ͻ�
// *last:������2���Ͻ�
// *temp:��ʱ��������
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
///*�ݹ�鲢����
// *���Σ���ɵݹ�鲢
// *list������������
// *first:list�½�
// *last:list�Ͻ�
// *temp:��ʱ��������
//*/
//void mergesort(element list[], int first, int last, element temp[])
//{
//    if (first < last)
//    {
//        int mid = (first + last) / 2;
//        mergesort(list, first, mid, temp);    //�������
//        mergesort(list, mid + 1, last, temp); //�ұ�����
//        Merge(list, first, mid, last, temp); //�ٽ������������кϲ�
//    }
//    return ;
//}
///*�ݹ�鲢����
// *list������������
// *n:Ϊ���鳤��
//*/
//bool MergeSort(element list[], int n)
//{
//    element *p = new element[n];//�ռ临�Ӷ�ΪO(n)
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
        return;//ÿ�����б���ʣ��һ��Ԫ��ʱֹͣ
    else
        mid=(low+high)/2;
    MergeSort(low,mid);//���б��һ������
    MergeSort(mid+1,high);

    //�½�һ�����飬���ڴ�Ź鲢��Ԫ��

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
    for( int j = 0,k=0;j<=high; j++,k++) //����ڶ������б�����Ȼ��Ԫ�أ���׷�ӵ����б�
        b[k]=arr[j];
    for( int i=0,k=0;i<=mid; i++,k++) //����ڵ�һ�����б�����Ȼ��Ԫ�أ���׷�ӵ����б���
        b[k]=arr[i];
    for(int z=0; z<high-low+1; z++) //�����������B�� ����Ԫ�ظ��Ƶ�ԭʼ����arr��
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
