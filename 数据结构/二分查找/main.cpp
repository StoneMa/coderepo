#include <iostream>
#include <cstdio>
using namespace std;
static int binSearch(int *A, int e,int lo, int hi);
int main()
{
    int a[5] = {1,2,3,4,5};
    cout<<binSearch(a,4,0,5);
    return 0;
}

//rank vector<T>::search(T const &e,rank lo, rank hi) const
//{
//    return(rand)
//}

static int binSearch(int *A, int e,int lo, int hi)
{
    while(lo<hi)
    {
        int mi = (lo+hi)>>1;
        if(e<A[mi]) hi = mi;
        else if(A[mi]<e) lo = mi+1;
        else return mi;
    }
    return  -1;
}
