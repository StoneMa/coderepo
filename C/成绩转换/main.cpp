#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float t;
    while(scanf("%f",&t)!=EOF){
        if(t>=90&&t<=100) cout<<"A"<<endl;
        if(t>=80&&t<=89) cout<<"B"<<endl;
        if(t>=70&&t<=79) cout<<"C"<<endl;
        if(t>=60&&t<=69) cout<<"D"<<endl;
        if(t>=0&&t<=59) cout<<"E"<<endl;
        if(t<0||t>100) cout<<"Score is error!"<<endl;
    }
}
