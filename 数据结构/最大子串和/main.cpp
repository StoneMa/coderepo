#include <iostream>
#define MAXSIZE 100
using namespace std;
int MaxSum(int [],int);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
int MaxSum(int a[],int n)
{
    int b = 0;
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(b>0)
        {
            b+=a[i];
        }
        else
        {
            b = a[i];
        }
        if(b>sum)
        {
            sum = b;
        }
    }
    return sum;
}
