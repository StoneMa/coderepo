#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int a,b;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&a,&b);
            if(a%b)
                printf("NO\n");
            else
                printf("YES\n");
        }
    return 0;
}
