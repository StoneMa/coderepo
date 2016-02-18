#include <iostream>
#include <stdio.h>
#define N 105
using namespace std;
int n;
int _0num,_1num,_2num;
float a[N];
int main()
{
    while(cin>>n,n)
    {
        _0num = _1num = _2num =0;//÷√ø’£ª
        for(int i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
            if(a[i]==0) _0num+=1;
            if(a[i]>0) _1num+=1;
            if(a[i]<0) _2num+=1;
        }
        printf("%d %d %d\n",_2num,_0num,_1num);
    }
    return 0;
}
