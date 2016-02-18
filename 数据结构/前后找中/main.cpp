#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100009
int pri[N],mid[N],last[N];
int top = 0;
void getlr(int l,int r,int _l,int _r){
      // printf("%d,%d,%d,%d\n",l,r,_l,_r);
      if(l==r){
            mid[top++] = pri[l];
            return;
      }
      int k = 0;
      for(int i = _l;i<=_r;i++){
            if(last[i]==pri[l+1]){
                k = i;
                break;
            }
      }
      int len = k - _l + 1;
      getlr(l+1,len+l,_l,k);
      mid[top++] = pri[l];
      getlr(len+l+1,r,k+1,_r-1);
}
int main(){
    int n;
    freopen("Test.txt","r",stdin);
    while(~scanf("%d",&n)){
            top =1;
            for(int i = 1;i<=n;i++) scanf("%d",&pri[i]);
            for(int i = 1;i<=n;i++) scanf("%d",&last[i]);
            getlr(1,n,1,n);
            for(int i = 1;i<=n-1;i++) printf("%d ",mid[i]);
            printf("%d\n",mid[n]);
    }
    return 0;
}
