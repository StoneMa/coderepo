#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 10010
using namespace std;

double minPro(double a,double b);
int main()
{
    double dp[N];
    int n,m;//�ֱ��ʾ��ͷǮ������ѧУ������
    int a[N];//��ʾÿ��ѧУ��Ӧ���������
    double b[N];//��ʾÿ��ѧУoffer�ĸ��ʣ�
    double p[N];//��ʾÿ��ѧУ���ܵõ�offer�ĸ��ʣ�
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
