#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 90
int main()
{
    int sum;
    int lenth_a,lenth_s;
    char a[N],s[N];
    while(true)
    {
        gets(a);
        if(a[0]=='#')
            break;
        gets(s);
        lenth_a = strlen(a);
        lenth_s = strlen(s);
        for(int i=0;i<lenth_a;i++)
        {
            sum = 0;//Ã¿´ÎÖÃ¿Õ
            for(int j=0;j<lenth_s;j++)
            {
                if(s[j]==a[i]) sum++;
            }
            printf("%c %d\n",a[i],sum);
        }
    }
    return 0;
}
