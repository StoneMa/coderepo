#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int year,month,day;
    int i;
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
    i=0;
    switch(month-1){
        case 11: i+=30;
        case 10: i+=31;
        case 9:  i+=30;
        case 8:  i+=31;
        case 7:  i+=31;
        case 6:  i+=30;
        case 5:  i+=31;
        case 4:  i+=30;
        case 3:  i+=31;
        case 2:  if((year%4==0&&year%100!=0)||(year%400==0))
            i+=29;
        else
            i+=28;
        case 1:  i+=31;
    }
    i+=day;
    printf("%d\n",i);
    }
    return 0;
}
