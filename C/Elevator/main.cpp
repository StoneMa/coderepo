#include <iostream>
using namespace std;
int main()
{
    int n;
    int startNow=0,nextFloor;
    int totalTime;
    while(cin>>n,n){
        totalTime=nextFloor=startNow=0;
        for(int i=0;i<n;i++){
            cin>>nextFloor;
            if(nextFloor>startNow){
                totalTime+=6*(nextFloor-startNow);
            }
            else{
                totalTime+=4*(startNow-nextFloor);
            }
            totalTime+=5;
            startNow = nextFloor;
        }
        cout<<totalTime<<endl;
    }
    return 0;
}
