#include <stdio.h>
#define N 100
int main()
{
    int n;
    int i;
    int sum=0;
    int a[N];
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        else if(n>=100||n<0)
            continue;
        else{
            for( i =0;i<n;i++){
                scanf("%d",&a[i]);
                if(a[i]>100||a[i]<=0){
                    i--;
                    continue;
                }else
                {
                    if(i==0){

                            sum = a[i]*6+5;

                    } else if(a[i]>a[i-1]){

                        sum = sum +(a[i]-a[i-1])*6+5;

                    } else if (a[i]<a[i-1]){

                        sum = sum + (a[i-1]-a[i])*4+5;

                    }else {

                        sum = sum+5;
                    }
                }
            }
        }
        printf("%d",sum);
        printf("\n");
    }
    return 0;
}
