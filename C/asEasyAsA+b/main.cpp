#include <iostream>
#include "stdio.h"
#define N 1005
using namespace std;

int main()
{
    int numOfTestCase;
    int numOfEachTestCase;
    int a[N];
    int next;
    cin>>numOfTestCase;
    while(numOfTestCase>0){
            cin>>numOfEachTestCase;
       for(int i=1;i<=numOfEachTestCase;i++){
            cin>>a[i];
       }
       for(int i=1;i<=numOfEachTestCase-1;i++){
            for(int j=1;j<=numOfEachTestCase-i;j++){
                 if(a[j]>a[j+1])
                {
                    a[0]=a[j+1];
                    a[j+1]=a[j];
                    a[j]=a[0];
                }
            }

       }
        for(next=1;next<=numOfEachTestCase;next++){
            printf("%d",a[next]);
            if(next!=numOfEachTestCase)
                printf(" ");
                }
        if(next!=numOfTestCase)
            printf("\n");
        numOfTestCase--;
    }
    return 0;
}
