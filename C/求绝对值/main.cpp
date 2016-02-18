#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double num;
    while(cin>>num){
        if(num<0)
            printf("%.2lf\n",-num);
        else
            printf("%.2lf\n",num);
    }
    return 0;
}
