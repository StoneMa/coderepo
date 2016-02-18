#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,j,k,t;
    char a[1001][16];
    while(scanf("%d",&n),n)
    {
        int  b[1001]={0};
        for(i=0;i<n;i++)//每输入一个颜色就对它进行一次处理
        {
            scanf("%s",a[i]);
            for(j=0;j<=i;j++)
            {
                if(strcmp(a[i],a[j])==0)//查看前面是不是有这个颜色出现
                {
                    b[j]++;//如果出现则颜色次数+1
                    break;//并且跳出循环本次，否则它会把出现在第二次，第三……出现的相同颜色做累加
                }
            }
        }
        for(i=0;i<n;i++)//比较数组总最大的数，这个数就是颜色出现最多的颜色数组的下标
        {
            k=0;
            for(j=0;j<n;j++)
            {
                if(b[i]>=b[j])
                k++;
            }
                if(k==n)
                {
                    t=i;
                    break;
                }
        }
        printf("%s\n",a[t]);
    }
    return 0;
}


