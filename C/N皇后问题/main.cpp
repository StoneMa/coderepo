//�˻ʺ����� ���ݷ�
#include<stdio.h>
int tot=0,row,line[10],n;
int main()
{
    void search(int );
    int a[11];
    for(n=1;n<=10;n++) //֮ǰ����û����һ��Ԥ��������TLE�� TT
    {
        tot=0;
        search(0);
        a[n]=tot;
    }
    while(scanf("%d",&n)!=EOF&&n)
         printf("%d\n",a[n]);
    return 0;
}
void search(int row) //�ݹ��������н�
{
    int i,j;
     if(row==n) tot++; //��row=nʱ��˵��ÿһ�еĻʺ󶼲���ͻ����Ϊ���н�
     else
     for(i=0;i<n;i++)
     {
         int ok=1;
         line[row]=i; //���԰ѵ�row�еĻʺ����i����
         for(j=0;j<row;j++) //�����Ƿ���ǰ���ѷźõĻʺ��ͻ
         {
             if(line[row]==line[j]||line[row]-row==line[j]-j||line[row]+row==line[j]+j)
             {
                 ok=0;
                 break; //���������ڲ�ѭ�������ͻ��ֹͣ������������һ���ݹ���ݡ����ݷ���Ч�Ĺؼ���
             }
         }
         if(ok)
             search(row+1);
     }
}
