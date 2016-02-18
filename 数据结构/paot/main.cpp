#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void put(char *order_rev_link,int now,int base)
{
    for( ;now<=base;now++)
    printf("%c",order_rev_link[now]);
    printf(" ");
}

int main()
{
    int i,j,n;
    char order_rev[100];
    gets(order_rev);
    n = strlen(order_rev);
    j = n-1;
    for(i=n-1;i>=0;i--)
    {
        if(order_rev[i]==' ')
        {
            put(order_rev,i+1,j);
            while(order_rev[i] == ' ' )i--;
            j = i-1;
        }
        if(i==0)
            put(order_rev,i,j);
    }
}
