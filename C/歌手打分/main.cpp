#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define  N 105
int main()
{
    int n;
    float sum;
    float a[N];
    while(scanf("%d",&n)!=EOF)
    {
        sum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
        }
        sort(a,a+n);
        for(int i=1;i<n-1;i++)
        {
            sum+=a[i];
        }
        printf("%.2f\n",sum/(n-2));
    }
    return 0;
}
