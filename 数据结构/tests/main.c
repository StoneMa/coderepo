#include "stdio.h"
void main()
{
    int n[][3] = {10,20,30,40,50,60};
    int (*p)[3];
    p = n;
    printf("%d %d %d",p[0][0],*(p[0]+1),(*p)[2]);
}
