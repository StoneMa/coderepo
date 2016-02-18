#include <iostream>
#define N 1000
using namespace std;
//第一次写的有问题，想的太简单了，单纯的认为楼层的高度都是两个高的夹着一个矮的。
int main()
{
    int building[N];
    int n;
    int sum = 0;
    int temp;
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            cin>>building[i];
        }
        for(int i=1;i<n-1;i++){
            temp =  building[i-1]>building[i+1]?building[i+1]:building[i-1];
            if(building[i]<temp){
                sum += temp - building[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

