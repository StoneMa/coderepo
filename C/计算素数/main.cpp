#include <iostream>
#include <stdio.h>
using namespace std;
int prime(int x);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
         cout << prime(n) << endl;
    }

    return 0;
}

int prime(int x){
    int i;
    if(x<2) return 0;
    for(i=2;i*i<=x;i++){
        if(x%i==0)  return 0;
    }
     return 1;
}
