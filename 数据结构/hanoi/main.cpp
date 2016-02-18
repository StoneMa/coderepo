#include <iostream>

using namespace std;
void hanoi(int n,char a,char b,char c);
char a,b,c;
int main()
{
    hanoi(3,'a','b','c');
    return 0;
}

void hanoi(int n,char a,char b,char c)
{
    if(n==1) cout<<"n="<<n<<"Ê±£º"<<a<<"->"<<c<<endl;
    else
    {
    hanoi(n-1,a,c,b);
    cout<<"n="<<n<<"Ê±£º"<<a<<"->"<<c<<endl;
    hanoi(n-1,b,a,c);
    }
}
