#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double x1,y1,x2,y2;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF){
        printf("%.2f\n",sqrt(pow((x1-x2),2.0)+pow((y1-y2),2.0)));
    }
    return 0;
}
