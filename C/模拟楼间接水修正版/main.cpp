#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int flag=0;
    int n;
    int sum,temp,maxNum;
    while(cin>>n,n){
            sum = 0;
       for(int i=0;i<n;i++){
            cin>>a[i];
        }
        maxNum = a[0];
        for(int i=0;i<n-1;i++){
            if(maxNum<a[i+1]){
                maxNum = a[i+1];
                flag = i+1;
            }
        }
        if(flag == 0){
            temp = a[n-1];
            for(int i=n-1;i>flag;i--){
                if(temp<=a[i-1]){
                    temp = a[i-1];
                }
                if(temp>a[i-1]){
                    sum += temp-a[i-1];
                }
            }
            cout<<sum<<endl;
            return 1;
        }
        if(flag == n-1){
        temp = a[0];
        for(int i=0;i<flag;i++){
            if(temp<=a[i+1]){
                temp=a[i+1];
            }
            if(temp>a[i+1]){
                sum += temp-a[i+1];
            }
        }
        cout<<sum<<endl;
        }
        else{
        temp = a[0];
        for(int i=0;i<flag;i++){
            if(temp<=a[i+1]){
                temp=a[i+1];
            }
            if(temp>a[i+1]){
                sum += temp-a[i+1];
            }
        }
        temp = a[n-1];
        for(int i=n-1;i>flag;i--){
            if(temp<=a[i-1]){
                temp = a[i-1];
            }
            if(temp>a[i-1]){
                sum += temp-a[i-1];
            }
        }
        cout<<sum<<endl;
        }
    }
    return 0;
}
