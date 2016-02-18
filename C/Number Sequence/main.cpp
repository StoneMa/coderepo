#include <iostream>
using namespace std;
int main()
{
    int a,b,n,i,f[55] = {0,1,1};
    while(cin >> a >> b >> n && (a!=0||b!=0||n!=0))
    {
              for (i = 3;i <= 49;i++)
                  f[i] = (a*f[i-1] + b*f[i-2])%7;
              cout << f[n%48] << endl;
    }
    return 0;
}
