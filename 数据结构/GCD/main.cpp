#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    cout<<gcd(a,b)<<endl;
    return 0;
}

int gcd(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(a%b==1)
        return 1;
    else if(a%b==0)
        return b;
    else
        return gcd(a%b,b);
}
