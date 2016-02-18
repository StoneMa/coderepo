#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n,k;
    float y;
    int sum1,sum2;
    float sum;
    while(scanf("%d%d%f",&n,&k,&y)!=EOF)
    {
        sum1 = sum2 = sum = 1;
        for(int i=k;i>=1;i--)
        {
            sum1 *=i;
        }
        for(int i=k+1;i<n;i++)
        {
            sum2 *= i;
        }
        sum = sum2/sum1;
        sum = sum*pow((1-y),k)*pow(y,(n-k));
        printf("%.2f\n",sum);
    }
    return 0;
}
