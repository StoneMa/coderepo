#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 100
using namespace std;

int main()
{
    int n;
    int a[N];
    int pro=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2!=0) pro*=a[i];
        }
        cout<<pro<<endl;
        pro = 1;
    }
    return 0;
}
