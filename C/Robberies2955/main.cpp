#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int m[101];
double p[101],dp[10001];
int main()
{
    int t,n,i,j,sum;
    double P;
    cin >> t;
    while(t-- && cin >> P >> n)
    {
              sum = 0;
              P = 1 - P;
              for(i = 0;i < n;i++)
              {
                    cin >> m[i] >> p[i];
                    sum += m[i];
                    p[i] = 1 - p[i];
              }
              memset(dp,0,sizeof(dp));
              dp[0] = 1;
              for(i = 0;i < n;i++){
                    //cout<<"��"<<i<<"�θ���"<<endl;
                    cout<<endl;
                 for(j = sum;j >= m[i];j--){
                         if(dp[j] < dp[j-m[i]]*p[i])
                                   dp[j] = dp[j-m[i]]*p[i];
                                   //cout<<"��ǰ͵"<<j<<"Ԫʱ"<<"���ܸ�����:"<<dp[j]<<endl;
                                   cout<<dp[j]<<"  ";
                    }
              }
              for(i = sum;i >= 0&&dp[i] < P;i--){
                //cout<<"��ǰ���ܸ���Ϊ:"<<dp[i]<<endl;
              }
              cout << i << endl;
    }
    return 0;
}
