#include <iostream>
#include <stdio.h>
using namespace std;
void swith(char*x,char*y);
int main()
{
    char a,b,c;
    while(scanf("%c%c%c",&a,&b,&c)!=EOF){
        if(a>b)
            swith(&a,&b);
        if(b>c)
            swith(&b,&c);
        if(a>b)
            swith(&a,&b);
        printf("%c %c %c\n",a,b,c);
            getchar();
    }
    return 0;
}

void  swith(char *x,char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
