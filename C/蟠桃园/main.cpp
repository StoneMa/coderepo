#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int sum;
int recursion(int x,int i)
{
    sum = (x+1)*2;
    i--;
    if(i==1) return sum;
    else
        return recursion(sum,i);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cout<<recursion(1,n)<<endl;
    }
    return 0;
}
