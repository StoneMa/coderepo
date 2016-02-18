#include <iostream>

using namespace std;
int set(int a);
int main()
{
    return 0;
}
int set(int a)
{
    if(disjoint[a]==-1)
        return a;
    else
        return disjoint[a] = findSet(disjoint[a]);
}
