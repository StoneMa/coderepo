#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1005
//̰���㷨��û��֮ǰ����Ϊ������ⶼ����ѣ����ǿ�������⣬����Ҳ����ô����
//˼·�ܼ򵥣��Ȱ�J[i]/F[i]���дӴ�С��������������ȡ�����ܱ�֤ȡ���������ġ�
int main()
{
    int m, n;
    int j[N],f[N],flag[N];
    double temple[N],temp;
    double sum;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        sum = 0;
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&j[i],&f[i]);
            temple[i] = 1.0*j[i]/(1.0*f[i]);
            flag[i] = i;//��ÿ��������Ϻš�
        }
//�Ա�ֵ��������ͬʱ�����������
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(temple[j]<temple[j+1])
                {
                    temp = temple[j];
                    temple[j] = temple[j+1];
                    temple[j+1] = temp;
                    //���������
                    temp = flag[j];
                    flag[j] = flag[j+1];
                    flag[j+1] = temp;
                }
            }
        }
        //����Ž����������
        //����������ļ���׶�
        for(int i=0;i<n;i++)
        {
            if(m<=0) break;
           if(m-f[flag[i]]>=0)
           {
                sum +=j[flag[i]];
                m = m-f[flag[i]];
           }
           else
           {
                sum+=1.0*m/(1.0*f[flag[i]])*j[flag[i]];
                m=0;
           }
        }
        printf("%.3f\n",sum);
    }

    return 0;
}
