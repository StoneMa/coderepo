#include <iostream>
#include <stdio.h>
#include <math.h>
#define N 1000
using namespace std;

int main()
{
    int m,n;
    int num[N]={0};
    int a,b,c;
    int has,j;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        j=1;
        has =0;
        for(int i=m;i<=n;i++)
        {
            a = i%10;
            b = (i%100)/10;
            c = i/100;
            if(i==(a*a*a+b*b*b+c*c*c))
            {
                num[j] = i;
                j++;
                has++;
            }
        }
        if(has)
        {
            for(int i=1;i<=j-1;i++)
            {
                if(i==j) printf("%d",num[i]);
                else printf("%d ",num[i]);
            }
        }
        if(!has) printf("no");
        printf("\n");
    }
}
