#include <iostream>
#include <stdio.h>
using namespace std;
#define N 60
int main()
{
    int n,m;
    float a[N][N];
    int num;
    bool flag = true;
    float avrgPerson,avrgLession;
    float everyLession[N];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        num = 0;
//����ÿ��ͬѧ�ĳɼ�
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%f",&a[i][j]);
            }
        }
//ÿ��ͬѧ��ƽ���ɼ�����
        for(int i=0;i<n;i++)
        {
            avrgPerson = 0;
            for(int j=0;j<m;j++)
            {
                avrgPerson+=a[i][j];
            }
            if(i<n-1)
                printf("%.2f ",avrgPerson/m);
            else
                printf("%.2f\n",avrgPerson/m);
        }
//ÿ��ѧ�Ƶ�ƽ���ɼ�����
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                avrgLession+=a[j][i];
            }
            if(i<m-1)
                printf("%.2f ",avrgLession/n);
            else
                printf("%.2f\n",avrgLession/n);
            //��¼ÿ�Ƶ�ƽ���ɼ�
            everyLession[i] = avrgLession/n;
            avrgLession = 0;//ÿ�μ���ÿ��ƽ���ɼ�ʱ��Ҫ�ÿ�
        }
//ͳ����������
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]<everyLession[j])
                    flag = false;
            }
            if(flag) num++;
            flag = true;
        }
        printf("%d\n\n",num);

    }
    return 0;
}
