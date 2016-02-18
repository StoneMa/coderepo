#include <iostream>
#include <stdio.h>

using namespace std;
int binSearch(int a[],int sIndex, int eIndex, int x );
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    printf(" 循环次数=%d",binSearch(a,0,9,3));
    return 0;
}
 int binSearch(int a[],int sIndex, int eIndex, int x )
 {
     int left,right,mid;
     int cNum=0;
     left = sIndex,right = eIndex;
     while(left<=right)
    {
        static int i=1;
        printf("经过%d遍",i++);
        ++cNum;
        printf("%d\n",cNum);
        mid = (left+right)/2;
        if(a[mid]==x)
        {
            printf("get it");
            return mid;
        }
        else if(a[mid]<x)
        {
            left = mid +1;
        }
        else if(a[mid]>x)
        {
                right = mid-1;
        }
     }
        return -1;
 }
