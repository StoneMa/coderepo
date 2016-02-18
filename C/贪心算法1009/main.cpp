#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1005
//贪心算法，没做之前本以为这类的题都会很难，但是看了这道题，发现也就那么回事
//思路很简单，先按J[i]/F[i]进行从大到小排序，这样依次来取，就能保证取到的是最多的。
int main()
{
    int m, n;
    int j[N],f[N],flag[N];
    double temple[N],temp;
    double sum;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        sum = 0;
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&j[i],&f[i]);
            temple[i] = 1.0*j[i]/(1.0*f[i]);
            flag[i] = i;//给每个房间标上号。
        }
//对比值进行排序，同时房间进行排序
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(temple[j]<temple[j+1])
                {
                    temp = temple[j];
                    temple[j] = temple[j+1];
                    temple[j+1] = temp;
                    //更换房间号
                    temp = flag[j];
                    flag[j] = flag[j+1];
                    flag[j+1] = temp;
                }
            }
        }
        //房间号降序排序完毕
        //下面进行最后的计算阶段
        for(int i=0;i<n;i++)
        {
            if(m<=0) break;
           if(m-f[flag[i]]>=0)
           {
                sum +=j[flag[i]];
                m = m-f[flag[i]];
           }
           else
           {
                sum+=1.0*m/(1.0*f[flag[i]])*j[flag[i]];
                m=0;
           }
        }
        printf("%.3f\n",sum);
    }

    return 0;
}
