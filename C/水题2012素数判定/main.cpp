#include <iostream>
#include <stdio.h>
using namespace std;

int prime(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
        return 0;
    return 1;
}

int main()
{
    int x,y,aim;
    int prime(int x);
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        bool flag=true;
        if(x>y)
        {
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
        if(x==0&&y==0) break;
        for(int i=x;i<=y;i++)
        {
            aim = i*i+i+41;
            if(!prime(aim))
            {
                 flag = false;
                 break;
            }
        }
        if(flag) printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}

