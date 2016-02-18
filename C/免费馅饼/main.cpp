#include <iostream>
#include <cstdio>
#include <string.h>
#define N 100010
using namespace std;
void input();
int maxThree(int a,int b,int c);
int maxTwo(int a,int b);

int n;
int total[100010][11];
int x,T,maxTime;
int main()
{
    while(scanf("%d",&n),n){
            memset(total,0,sizeof(total));
            maxTime=0;
            while(n--){
                 scanf("%d%d",&x,&T);
                 total[T][x]++;
                 maxTime = maxTime>T?maxTime:T;
            }
            for(int i = maxTime -1;i>=0;i--){
                for(int j=0;j<=10;j++){
                    if(j==0)
                        total[i][j]+=maxTwo(total[i+1][j],total[i+1][j+1]);
                    else if(j==10)
                        total[i][j]+=maxTwo(total[i+1][j],total[i+1][j-1]);
                    else
                        total[i][j]+=maxThree(total[i+1][j],total[i+1][j-1],total[i+1][j+1]);
                }
            }
            printf("%d\n",total[0][5]);
    }
    return 0;
}

int maxTwo(int a,int b){
    a = a>b?a:b;
    return a;
}
int maxThree(int a,int b,int c){
    a = a>b?a:b;
    a = a>c?a:c;
    return a;
}
