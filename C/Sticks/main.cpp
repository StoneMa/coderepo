#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 22
using namespace std;
int vis[M];
int num[M];
int n, m;
bool cmp(int a,int b)//控制排序方式。DESC
{
    return a>b;
}
bool dfs(int remd,int pos,int count,int len)
//remd正方形的每个边的理论剩余边长，pos当前搜索位置，count已组成理论边的个数，
{
    int i;
    if(count==4)
    {
        return 1;
    }
    for(i=pos;i<=m-1;i++)
    {
        if((!vis[i])&&remd>=num[i])//mian函数中已经对比了remd和数组的第一个木条长度进行了比较。（其实main中比较的那部分代码可以省去。）
        {
            vis[i]=1;
            remd=remd - num[i];//至此reamd为使用了num[i]木条后，还差的长度。
            if(remd==0&&dfs(len,0,count+1,len))//如果remd为0，那么表示该边已经和理论边吻合。那么让已构成的边数+1，继续dfs。
                                                        //这里的dfs目的是进入下一层循环检测是否已经四条边全部构成，所以第一个参数直接写理论边。
            {
                return 1;
            }else if(dfs(remd,i+1,count,len))//如果remd减去num[i]后还有剩余，那么进入下一层dfs，重复remd的操作。直至remd为0。
            {
                return 1;//这个题简单的地方就在于每个木条都必须用上，不能有剩余，所以如果从前面搜有不符合的，直接返回return 0；
            }
            //搜索到最后一根木条时发现还是不能满足，就运行for循环外面的return 0 ;然后依次递归回退到上一层的
            //dfs，因为return 0，if条件不满足，所以运行下面的代码，把每次减去num[i]后的remd加回到原值。
            remd = remd + num[i];
            vis[i] = 0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    while(n--)
        {
            memset(vis,0,sizeof(vis));
            int sum = 0;
            scanf("%d",&m);
            for(int i=0;i<=m-1;i++)
            {
                scanf("%d",&num[i]);//num数组来记录输入的各个木条的长度。木条个数为m。
                sum+=num[i];
            }
            if(sum%4)
            {
                printf("no\n");
                continue;
            }
            sort(num,num+m,cmp);//sort排序，cmp函数控制为降序排列。
            if(sum/4<num[0])//如果最长的木棒比组成正方形的边长还长，就无法组成正方形。
            {
                printf("no\n");
                continue;//打印no，进入下一层循环。
            }
            if(dfs(sum/4,0,0,sum/4))//如果满足dfs，就是合适的方法。
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        return 0;
}
