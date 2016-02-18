#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1001
using namespace std;
int disjoint[N],flag[N];
int combine(int a,int b);
int findSet(int a);

int main()
{
    int numOfTown,numOfRoads;
    int xTown,yTown;
    int value;
    int k;
    while(cin>>numOfRoads>>numOfTown,numOfRoads)
    {
        memset(disjoint,-1,sizeof(disjoint));
        memset(flag,0,sizeof(flag));
        for(int i=0; i<numOfRoads; i++)
        {
            cin>>xTown>>yTown>>value;
            combine(xTown,yTown);
        }
        for(int i=1; i<=numOfTown; i++)
        {
            flag[findSet(i)] = 1;
        }
        //一定要在这里给k置零；
        k=0;

        for(int i=1; i<=numOfTown; i++)
        {
            if(flag[i]==1)
                k++;
        }
        cout<<k-1<<endl;
    }
      return 1;
}
int findSet(int a)
{
    if(disjoint[a]==-1)
        return a;
    else
        return disjoint[a] = findSet(disjoint[a]);
}

int combine(int a,int b)
{
    int fa = findSet(a);
    int fb = findSet(b);
    if(fa == fb)
    {
        return 0;
    }
    else{
        disjoint[fb] = fa;
        return 1;
    }
}
