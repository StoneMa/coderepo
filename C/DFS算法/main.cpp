/*
*��Ŀ:
*11223344556677����ȫ���У���11֮��1������22֮����������33֮��3������44֮��4��������
*˼·: ����ÿ��Ԫ����Ϊ���ڵ�������ѣ����ѹ����У�����ÿ��i���������Σ�����Ԫ��i��¼�����ֵĴ���use[i]����һ�γ���ʱ���1��
�ڶ��γ���ʱ���2����������һ�γ��ֵ�λ�ã����������͵�һ�γ��ֵ�ʱ���λ�õĲ�ֵʱ��պ�Ϊ���ǵ���ֵ��
������ڶ��γ��֣��Ҽ��鷵��ֵΪtrue����������2�����Ұ����浽��ǰ��������¼��ȷ��������������num[i]�����������������ѡ�

 */
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#define N 1000
using namespace std;
int use[N]; //�������ÿ��Ԫ�ص�ʹ�ô���;use[1]=0|1|2��ʾ��1ʹ����0|1|2�Σ�
int num[N];//�����洢ÿ�ν��н������ѵĽ����������ɶ�������ÿ���ѵ�Ҷ�ӽڵ㣬�ͽ����������
void dfs(int n,int t);
bool check(int a,int b);//����
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(use,0,sizeof(use));
        memset(num,0,sizeof(num));
  /*   num[0]=7;   //���磺�����Ǹ���Ҫ�󣬲�����7 4 ��ͷ��һ��������ô����ע���еĲ���
        num[1]=4;
        use[7]=1;
        use[4]=1;
    */
        dfs(n,0);
    }
    return 0;
}

bool check(int a,int b){
    int tag = 0;
    for(int i=0;i<b;i++){
        if((num[i])==a){ tag = i; break; }
    }
    if(b-tag-1==a) return 1;
    else return 0;
}
void dfs(int n,int t){
    for(int i = 1;i<=n;i++){
        if(use[i]==0){
            use[i]=1;
            num[t]=i;
            dfs(n,t+1);
            use[i]=0;
        }
        if(use[i]==1&&check(i,t)){
            use[i]=2;
            num[t]=i;
            dfs(n,t+1);
            use[i]=1;
        }
        if(use[i]==2)
            continue;
    }
        if(t==n*2){
        for(int i=0;i<2*n;i++){
            printf("%d ",num[i]);
        }
        printf("\n");
        getchar();//ÿ�λس���Ŵ�ӡһ��
        return;
    }
}
