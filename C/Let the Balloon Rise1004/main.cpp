#include <string.h>
#include <stdio.h>
int main()
{
    int n,k,t;
    char str[1010][16];

    while(scanf("%d",&n),n)
            {
        int num[1010] ={0};
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<=i;j++)
            {
                if(strcmp(str[i],str[j])==0)
                {
                    num[j]++;
                    break;
                }
            }
        }

        for(int i=0;i<n;i++)
      {
            k=0;
            for(int j=0;j<n;j++)
            {
                    if(num[i]>=num[j])
                        k++;
            }
             if(k==n)
            {
                t=i;
                break;
             }
        }
        printf("%s\n",str[t]);
    }
    return 0;
}
