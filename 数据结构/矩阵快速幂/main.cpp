#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int N;

struct matrix
{
       int a[3][3];
}origin,res;


matrix multiply(matrix x,matrix y)
{
       matrix temp;
       memset(temp.a,0,sizeof(temp.a));
       for(int i=0;i<3;i++)
       {
               for(int j=0;j<3;j++)
               {
                       for(int k=0;k<3;k++)
                       {
                               temp.a[i][j]+=x.a[i][k]*y.a[k][j];
                       }
               }
       }
       return temp;
}

void init()
{
     printf("随机数组如下:\n");
     for(int i=0;i<3;i++)
     {
             for(int j=0;j<3;j++)
             {
                     origin.a[i][j]=rand()%10;
                     printf("%8d",origin.a[i][j]);
             }
             printf("\n");
     }
     printf("\n");
     memset(res.a,0,sizeof(res.a));
     res.a[0][0]=res.a[1][1]=res.a[2][2]=1;                  //将res.a初始化为单位矩阵
}

void calc(int n)
{
    int p = n;
     while(n)
     {
             if(n&1)
                    res=multiply(res,origin);
             n>>=1;
             origin=multiply(origin,origin);
     }
     printf("%d次幂结果如下：\n",p);
     for(int i=0;i<3;i++)
     {
             for(int j=0;j<3;j++)
                     printf("%8d",res.a[i][j]);
             printf("\n");
     }
     printf("\n");
}
int main()
{
    while(cin>>N)
    {
            init();
            calc(N);
    }
    return 0;
}
