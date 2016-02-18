#include "stdio.h"
#include "math.h"
int main()
{

    int x[13],y[13];
    double sum[13][13];
    int i,j,k,a=0;
    for(i=0; i<=12; i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for(j=0; j<=12; j++)
    {
        for(k=0; k<=12; k++)
        {
            a=(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]);
            sum[j][k]=sqrt(a);
        }
    }

    for(i=0; i<=12; i++)
    {
        for(j=0; j<=12; j++)
        {
            printf("%0.2lf    ",sum[i][j]);
        }
        printf("\n");
    }
}
