#include <iostream>
#include <math.h>
#include <stdio.h>
#define N 10005
using namespace std;
double n;
int m;
double sum;
int main()
{
    while(scanf("%lf %d",&n,&m)!=EOF)
    {
        sum = 0;
        for(int i=0;i<m;i++)
        {
            sum+=n;
            n = sqrt(n);
        }
        printf("%.2f\n",sum);

    }
    return 0;
}
