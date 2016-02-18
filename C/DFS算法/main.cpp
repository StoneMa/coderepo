/*
*题目:
*11223344556677进行全排列，让11之间1个数，22之间两个数，33之间3个数，44之间4个数……
*思路: 对于每个元素作为根节点进行深搜，深搜过程中，由于每个i都出现两次，对于元素i记录它出现的次数use[i]，第一次出现时标号1，
第二次出现时标号2，搜索它第一次出现的位置，并检验它和第一次出现的时候的位置的差值时候刚好为他们的数值，
若满足第二次出现，且检验返回值为true，则给它标号2，并且把它存到当前的用来记录正确的输出结果的数组num[i]处，并继续进行深搜。

 */
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#define N 1000
using namespace std;
int use[N]; //用来标记每个元素的使用次数;use[1]=0|1|2表示：1使用了0|1|2次；
int num[N];//用来存储每次进行进行深搜的结果。（想象成二叉树，每次搜到叶子节点，就进行输出）；
void dfs(int n,int t);
bool check(int a,int b);//检验
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(use,0,sizeof(use));
        memset(num,0,sizeof(num));
  /*   num[0]=7;   //比如：问题是复合要求，并且以7 4 开头的一组数，那么可做注释中的操作
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
        getchar();//每次回车后才打印一行
        return;
    }
}
