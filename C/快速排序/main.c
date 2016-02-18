#include <stdio.h>
#include <stdlib.h>
void Qsort(int a[],int low,int high);
int OncePartition(int a[],int low,int high);
int main()
{
    int a[5] ={0,5,4,3,2};
    int i;
    Qsort(a,1,5);
    for(i=1;i<5;i++)
    printf("%d",a[i]);
    return 0;
}
int OncePartition(int a[],int low,int high){

    a[0]=a[low];
    while(low<high){
        while(low<high&&a[high]>=a[0]){
            high--;
        }
        if(low<high){
            a[low] = a[high];
        }
        while(low<high&&a[low]<=a[0]){
            low++;
        }
        if(low<high){
            a[high] = a[low];
        }
    }
    a[low]=a[0];
    return *a;
}
void Qsort(int a[], int low,int high){
    int part;
    if(low<high){
        part = OncePartition(a,low,high);
        Qsort(a,low,part-1);
        Qsort(a,part+1,high);
    }
}
