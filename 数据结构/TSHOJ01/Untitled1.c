#include <stdio.h>
#define M 50009
int main()
{
    int n,m;
    int i,j;
    long a,b;
    long p[M];
    int num;
    scanf("%d,%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%ld",p[i]);
    }
    for(j=0;j<m;j++)
    {
        num = 0;
        scanf("%ld%ld",&a,&b);
        for(i=0;i<n;i++)
        {
            if(p[i]>=a&&p[i]<=b)
                num++;
        }
        printf("%d",num);
        if(j!=m-1)
            printf("\n");
    }
}
