#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
   int n;
   int cou,sum;
    while(scanf("%d",&n)!=EOF)
    {
        cou = 1;
        sum = 1;
        for(int i=1,j=2;i<=j&&cou<n;i++)
        {
            if(i<j) ++sum;
            if(i==j)
            {
                    --sum;
                    ++j;
                    i=0;
            }
            ++cou;
            if(cou==n) break;
        }
        printf("%d\n",sum);

    }
}
