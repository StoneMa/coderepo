#include <iostream>
#include <stdio.h>
using namespace std;
long long factorial(long long num);
int main()
{
    long long n;
    while(scanf("%I64d",&n)!=EOF){
    cout<<factorial(n)<<endl;
    }
    return 0;
}

long long factorial(long long num)
{
    long long t;
    if(num == 1) return 1;
    else {
        t = factorial(num-1);
        return t*num;
    }
}
