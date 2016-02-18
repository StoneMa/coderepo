#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int m,n,temp;
    int doubleSum=0,triSum=0;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m>n) {temp = m;m=n;n=temp;}
        for(int i=m;i<=n;i++)
        {
            if(i%2==0){doubleSum+=i*i;}
            else triSum += i*i*i;
        }
        cout<<doubleSum<<" "<<triSum<<endl;
        doubleSum = triSum =0;
    }
    return 0;
}
