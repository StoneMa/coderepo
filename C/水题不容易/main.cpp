#include <iostream>
#include <stdio.h>
using namespace std;
#define N 1000
int main()
{
    int n;
    int a;
    int sum;
    scanf("%d",&n);
    while(n--)
    {
        sum = 3;
        scanf("%d",&a);
        for(int i=0;i<a;i++)
        {
            sum = (sum-1)*2;
        }
        printf("%d\n",sum);
    }
    return 0;
}
