//八皇后问题 回溯法
#include<stdio.h>
int tot=0,row,line[10],n;
int main()
{
    void search(int );
    int a[11];
    for(n=1;n<=10;n++) //之前就是没有这一步预处理，所以TLE了 TT
    {
        tot=0;
        search(0);
        a[n]=tot;
    }
    while(scanf("%d",&n)!=EOF&&n)
         printf("%d\n",a[n]);
    return 0;
}
void search(int row) //递归搜索可行解
{
    int i,j;
     if(row==n) tot++; //当row=n时，说明每一行的皇后都不冲突，即为可行解
     else
     for(i=0;i<n;i++)
     {
         int ok=1;
         line[row]=i; //尝试把第row行的皇后放在i列上
         for(j=0;j<row;j++) //检验是否与前面已放好的皇后冲突
         {
             if(line[row]==line[j]||line[row]-row==line[j]-j||line[row]+row==line[j]+j)
             {
                 ok=0;
                 break; //，跳出最内层循环如果冲突，停止搜索，返回上一级递归回溯。回溯法高效的关键。
             }
         }
         if(ok)
             search(row+1);
     }
}
