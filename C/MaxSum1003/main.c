#include <stdio.h>
#define N 100010
int t;
int n;
int i,j,k;
int a[N];
int max,temp;
int lflag=1,rflag=1,flag=1;

int maxSum(int a[]);
int init();

int main(){
    scanf("%d",&t);
    for(i=1; i<=t; i++){
        init();
        scanf("%d",&n);
        for(j=0; j<n; j++){
            scanf("%d",&a[j]);
        }
        maxSum(a);
        printf("Case %d:\n",i);
        printf("%d %d %d\n",max,lflag,rflag);
        if(i!=t)printf("\n");
    }
    return 0;
}
int init(){
    flag = lflag = rflag = 1;
    return 0;
}
int maxSum(int a[]){
    max = a[0];
    temp = a[0];
    for(k=1; k<n; k++)
    {
        if(temp>0){
            temp += a[k];
        }
        else
        {
            temp=a[k];
            flag = k+1;
        }

        if(max<temp){
            max=temp;
            rflag = k+1;
            lflag = flag;
        }
    }
    return max;
}
