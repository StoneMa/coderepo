#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#define MAX 4000009
#define INF 1000000000
using namespace std;
typedef struct Node
{
    long x;
    long y;
}p;

p point[MAX];

long A[MAX];
long cunt=0;
long L[MAX],R[MAX];
const long M= INF;

int comp(const void *a,const void *b);
void MergeSort(long Left,long Right);
void Merge(long Left,long Middle,long Right);

int main()
{
    long n;
    scanf("%ld",&n);
    long i;
    for(i=0;i<n;i++)
        scanf("%ld%ld",&point[i].x,&point[i].y);
    qsort(point, n, sizeof(point[0]), comp);/*对坐标按照x的点位大小排序 */

        for(i=0;i<n;i++)
            A[i+1] = point[i].y;

        MergeSort(1,n);

        long tmp=(n*(n-1))>>1;
        printf("%ld\n",tmp-cunt);

        return 0;
}

int comp(const void *a,const void *b)
{
    long *pa = (long *)a;
    long *pb = (long *)b;
    return  *pa-*pb;
}

void MergeSort(long Left,long Right)
{
	long Middle;
	if(Left<Right)
	{
		Middle=(Left+Right)/2;
		MergeSort(Left,Middle);
		MergeSort(Middle+1,Right);
		Merge(Left,Middle,Right);
	}
}

void Merge(long Left,long Middle,long Right)
{
	long n1=Middle-Left+1;
	long n2=Right-Middle;

	long i,k;
	for(i=1;i<=n1;i++)
		L[i]=A[Left+i-1];
	for(i=1;i<=n2;i++)
		R[i]=A[Middle+i];
	L[n1+1]=M;
	R[n2+1]=M;
	i=1;
	long j=1;
	for(k=Left;k<=Right;k++)
	{
		if(L[i]<=R[j])
			A[k]=L[i++];

		else
		{
			A[k]=R[j++];
			cunt+=n1-i+1;                 //cunt为全局变量
		}
	}
}
