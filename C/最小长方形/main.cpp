#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 250
int main()
{
    int x[N],y[N];
    int i=0;
    while(true)
    {
        scanf("%d%d",&x[i],&y[i]);
            if(x[i]==0&&y[i]==0)
            {
                if(i==0)
                    break;
                if(i==1)
                   {
                        printf("%d %d %d %d\n",x[0],y[0],x[0],y[0]);
                        i = 0;
                        continue;
                   }
                else
                   {
                    sort(x,x+i);
                    sort(y,y+i);
                    printf("%d %d %d %d\n",x[0],y[0],x[i-1],y[i-1]);
                    memset(x,0,sizeof(x));
                    memset(y,0,sizeof(y));
                    i = 0;
                    continue;
                   }
            }
            i++;
    }
    return 0;
}
