#include<iostream>
#include <stdio.h>
using namespace std;
//���ڴ��Ź�ʽ�ĵݹ��㷨��n����һ���ж������Ŵ�Ŀ�����
int main()
{
	long long arr[21];
	int num,i;
	arr[1]=0;arr[2]=1;
	for(i=3;i<21;i++)
	arr[i]=(i-1)*(arr[i-1]+arr[i-2]);//�Ŵ�ʽ
	while(scanf("%d",&num)!=EOF)
	{
		cout<<arr[num]<<endl;
	}
}
