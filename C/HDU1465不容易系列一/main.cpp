#include<iostream>
#include <stdio.h>
using namespace std;
//基于错排公式的递归算法，n封信一共有多少种排错的可能性
int main()
{
	long long arr[21];
	int num,i;
	arr[1]=0;arr[2]=1;
	for(i=3;i<21;i++)
	arr[i]=(i-1)*(arr[i-1]+arr[i-2]);//排错公式
	while(scanf("%d",&num)!=EOF)
	{
		cout<<arr[num]<<endl;
	}
}
