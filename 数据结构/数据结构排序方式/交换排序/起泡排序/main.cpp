/**
��������+�Ľ���������
�Ľ���
������forѭ���ĵ�һ���ڲ�����һ��flag = 1�ļ����ڣ�
���ڲ�ѭ����������Ĺ����У���������˽����������ڲ�forѭ��
��flag��Ϊ0��
���û�з���������flagά�����for��ֵ1�����������Ѿ����������ٽ���֮������forѭ����
����if��䣬����flag���ڲ�forû����0����������������ѭ�����Ӷ���ʡʱ�䡣
 **/
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
int main()
{
    int a[N],n;
    int flag;
    printf("��Ҫ��������ĸ�����\n");
    scanf("%d",&n);
    printf("����%d����\n",n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
        {
            flag = 1;
            for(int j = 1;j<=n-i;j++)
                if(a[j]>a[j+1])
                    {
                        a[0] = a[j+1];
                        a[j+1] = a[j];
                        a[j] = a[0];
                        flag = 0;
                    }
                    if(flag) break;//�����flag������Ϊ�ж������Ƿ��Ѿ�����ı�־������Ѿ����򣬱������ٽ�����һ��forѭ��
        }

            for(int i=1;i<=n;i++)
                printf("%d  ",a[i]);
    return 0;
}
