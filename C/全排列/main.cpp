#include <iostream>
#include <string.h>
#include <stdio.h>
#define N 100
using namespace std;

char* inputStr(int n);
void printfStr( char str[]);
char str[N];

int main()
{
    int n;
    cin>>n;
    cout<<"ÊäÈëÊý¾Ý"<<endl;
    inputStr(n);
    //printf("%s\n",str);
    printfStr(str);
    return 0;
}

char* inputStr(int n){
    char *pStr = str;
    for(int i=0;i<n;i++){
        str[i] = getchar();
    }
    str[n] = '\0';
    return pStr;
}

void printfStr(char str[]){
    char* p;
    p = str;
    while(*p != '\0'){
        cout<<p++<<endl;
    }
}
