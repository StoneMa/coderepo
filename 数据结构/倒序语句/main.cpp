/*
代码有问题/ 2015/10/13
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 100
using namespace std;

int main()
{
    char a[N];
    bool flag = true;
    int m=0;
    memset(a,0,sizeof(a));
    scanf("%c",&a[m]);
    int n=0;
    while(a[m]!='\n')
    {
        ++n;
        ++m;
        scanf("%c",&a[m]);

    }
    int i,j,k;
    for(i=n-1,j=i;i>=0;i--)
    {
        if(a[i]==' ')
        {
            for(k = i ; k<=j ; k++)
            {
                printf("%c",a[k]);
            }
            j = i;
        }
    }
    for(k=0;k<=j;k++)
        printf("%c",a[k]);
    return 0;
}
