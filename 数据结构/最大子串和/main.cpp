#include <iostream>
#include <stdio.h>
#define MAXSIZE 100
using namespace std;
int MaxSum(int [],int);
int main()
{
    int a[10];
    int i=0;
    while(i < 10){
        scanf("%d ",&a[i]);
        i++;
    }
    printf("%d\n",MaxSum(a,10));
    return 0;
}
int MaxSum(int a[],int n)
{
    int b = 0;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(b>0)
        {
            b+=a[i];
        }
        else
        {
            b = a[i];
        }
        if(b>sum)
        {
            sum = b;
        }
    }
    return sum;
}
