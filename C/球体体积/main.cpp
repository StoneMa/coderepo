#include <iostream>
#include <stdio.h>
#include <math.h>
#define  PI  3.1415927
using namespace std;

int main()
{
    double r;
    while(scanf("%lf",&r)!=EOF){
        printf("%.3lf\n",4.0/3*PI*pow(r,3));
    }
    return 0;
}
