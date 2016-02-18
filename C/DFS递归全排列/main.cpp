#include <iostream>
#include <cstdio>
#include <string.h>
#define N 1009
using namespace std;
int use[N];
int num[N];
int p=0;
void dfs(int n,int t);
int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        memset(use,0,sizeof(use));
        memset(num,0,sizeof(num));
        dfs(n,0);
        printf("%d\n",p);

    }
    return 0; }
void dfs(int n,int t) {
    if(t==n) {
        for(int i=0; i<n; i++) {
            printf("%d",num[i]); }
        ++p;
        printf("\n"); }
    for(int i = 1; i<=n; i++) {
        if(use[i]==0) {
            use[i]=1;
            num[t]=i;
            dfs(n,t+1);
            use[i]=0; } } }
//对字母进行全排列
/*
void dfsPro(int n,int t,char a[]){
    if(t==n){
        for(int i=0;i<n;i++){
            printf("%c ",num[i]);
        }
        printf("\n");
    }
    for(int i = 1;i<=n;i++){
        if(use[i]==0){
            use[i]=1;
            num[t]=a[i];
            dfsPro(n,t+1,a);
            use[i]=0;
        }
    }
} */
