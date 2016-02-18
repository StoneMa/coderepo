#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 10010
using namespace std;

double minPro(double a,double b);
int main()
{
    double dp[N];
    int n,m;//分别表示手头钱数，和学校总数；
    int a[N];//表示每个学校对应的申请费用
    double b[N];//表示每个学校offer的概率；
    double p[N];//表示每个学校不能得到offer的概率；
    while(cin>>n>>m&&n&&m){
        for(int i=0;i<m;i++){
            cin>>a[i]>>b[i];
            p[i]=1-b[i];
        }
        memset(dp,1.0,sizeof(dp));
        for(int i=0;i<m;i++)
            for(int j=n;j>=a[i];j--){
                dp[j] = minPro(dp[j],dp[j-a[i]]*p[i]);
            }
    }
        printf("%.1lf%%\n",(1-dp[n])*100);
    return 0;
}

double minPro(double a,double b){
    return a>b?b:a;
}
