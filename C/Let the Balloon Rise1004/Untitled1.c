#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,j,k,t;
    char a[1001][16];
    while(scanf("%d",&n),n)
    {
        int  b[1001]={0};
        for(i=0;i<n;i++)//ÿ����һ����ɫ�Ͷ�������һ�δ���
        {
            scanf("%s",a[i]);
            for(j=0;j<=i;j++)
            {
                if(strcmp(a[i],a[j])==0)//�鿴ǰ���ǲ����������ɫ����
                {
                    b[j]++;//�����������ɫ����+1
                    break;//��������ѭ�����Σ���������ѳ����ڵڶ��Σ������������ֵ���ͬ��ɫ���ۼ�
                }
            }
        }
        for(i=0;i<n;i++)//�Ƚ��������������������������ɫ����������ɫ������±�
        {
            k=0;
            for(j=0;j<n;j++)
            {
                if(b[i]>=b[j])
                k++;
            }
                if(k==n)
                {
                    t=i;
                    break;
                }
        }
        printf("%s\n",a[t]);
    }
    return 0;
}


