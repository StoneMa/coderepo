#include <iostream>

using namespace std;

int main()
{
    int n,reach=0;
    int u,d;
    int time=0;
   while(cin>>n,n){
        cin>>u>>d;
        while(reach!=n){
            reach+=u;
            ++time;
            if(reach>=n){
                    cout<<time<<endl;
                    break;
            }
            else{
            reach-=d;
            ++time;
            }
        }
        time = reach = 0;
   }
    return 0;
}
