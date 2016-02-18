/**
起泡排序+改进起泡排序
改进：
在两层for循环的第一层内部放置一个flag = 1的监视哨；
在内层循环经行排序的过程中，如果发生了交换，就在内层for循环
将flag置为0；
如果没有发生交换，flag维持外层for的值1；表明序列已经有序，无需再进行之后的外层for循环；
放置if语句，发现flag在内层for没有置0的情况，就跳出外层循环，从而节省时间。
 **/
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
int main()
{
    int a[N],n;
    int flag;
    printf("想要排序的数的个数：\n");
    scanf("%d",&n);
    printf("输入%d个数\n",n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
        {
            flag = 1;
            for(int j = 1;j<=n-i;j++)
                if(a[j]>a[j+1])
                    {
                        a[0] = a[j+1];
                        a[j+1] = a[j];
                        a[j] = a[0];
                        flag = 0;
                    }
                    if(flag) break;//这里的flag用来作为判断序列是否已经有序的标志，如果已经有序，便无序再进行下一层for循环
        }

            for(int i=1;i<=n;i++)
                printf("%d  ",a[i]);
    return 0;
}
