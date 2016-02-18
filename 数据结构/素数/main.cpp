#include <iostream>
#include <stdio.h>
using namespace std;
int Sushu(int x);
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",Sushu(a));
    return 0;
}

int Sushu(int x)
{
    if(x==2||x==1) return 1;
    else
    {
        for(int i=2;i<x;i++)
        {
            if(x%i==0)return 0;
        }
        return 1;
    }
}
