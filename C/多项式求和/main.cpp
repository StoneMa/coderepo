#include <iostream>
#include <stdio.h>
using namespace std;
#define N 1005
int main()
{
    double sum,sum1,sum2;
    int m,a[N];
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<m;i++)
    {
        sum=sum1=sum2=0;

        for(int j=1;j<=a[i];j++)
        {
            if(j%2==0)  sum1+=(double)-1/j;
            if(j%2==1) sum2+=(double)1/j;
        }
        sum = sum1+sum2;
        printf("%.2lf\n",sum);
    }
    return 0;
}
