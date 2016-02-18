#include <iostream>

using namespace std;

int dfs(int m);
int main()
{
    int m;
    cin>>m;
    cout<<dfs(m);
    return 0;
}

int dfs(int m){
    if(m==1)
        return 1;
    else
        return m+dfs(m-1);
}
