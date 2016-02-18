/**
    ��������
    �ؼ�˼�룺ÿ�������Ե�һ������Ԫ��Ϊ�Ƚ�������Ȼʵ�����Ҳ���������һ������������ʹ���м��������������������ȽϷ�������
    ���Σ�
    �����һ��λ����ǰ�����ȶԱ���С������
    ����ǰһ��λ����������ȶԱ����������
    ֱ��low��high��������ʱ  low = high�����Ե��������㷨����ν����low����high��
    ��ʱlow����high����λ�þ��ǵ�ǰ�Ա���a[0]������λ�ã�
    Ȼ���¼��ǰλ�ã����ö��ֵ�˼�룬����ǰ���ͺ󷽵�Ԫ�ؽ�����ͬ������ֱ��ȫ������
 **/
 //ÿһ����Ŷ���ȷ��һ����������λ�ã�֮�����������в��������������λ�õĸı䣻

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
                high--;//�Ӻ���ǰ���ң������ǰa[high]��a[0]�е�ֵ�󣬾ͼ�����ǰ������
            /** ��������whileѭ��֮���������if��� **/
            if(low<high)//������ѭ����ԭ��Ϊ���������˱�a[0]С��ֵ��
                a[low] = a[high];//����ǰ�ԱȻ�׼λ�õ�����Ԫ�ظ�ֵ��

            while((low<high)&&a[low]<=k)
                low++;//ͬһ�����Ҫ���д�ǰ�������

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
