#include <iostream>
#include "stdio.h"
using namespace std;
double factorial(int a);
double sum(int b);
int main()
{
    cout<<"n"<<" "<<"e"<<endl;
    cout<<"- -----------"<<endl;
    for(int i=0;i<10;i++){
        if(i!=0){
                if(i<=2)
                cout<<i<<" "<<sum(i)<<endl;
            else
            printf("%d %.9f\n",i,sum(i));
        }else
            printf("0 1\n");
    }
    return 0;
}
double factorial(int a){
    double coutNum=1.0;
    while(a>=1){
        coutNum*=a;
        a--;
    }
    return coutNum;
}
double sum(int b){
    double sum = 0.0;
    for(int i=1;i<=b;i++){
    sum += 1/factorial(i);
    }
    sum += 1;
    return sum;
}
