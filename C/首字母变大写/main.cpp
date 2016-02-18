#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[105];
int i,lenth;
int main()
{
    while(gets(a)!='\0')
    {
        lenth = strlen(a);
        if(a[0]!=' ') a[0] = a[0] -32;
        for(int i=1;i<lenth-1;i++)
        {
            if(a[i]==' '&&a[i+1]!=' ')
                a[i+1] = a[i+1]-32;
        }
        puts(a);
    }
    return 0;
}
