#include<stdio.h>
#include<string.h>
struct boat
{
	int time;
	int flag;
}a[105];
int count; /*��¼����*/
double sum; /*��¼ʱ��*/
int main()
{
	int num,h,m;
	char c;
	sum=0;
	count=0;
	memset(a,0,sizeof(a)); /*��ʼ��*/
	while(1)
	{
		scanf("%d",&num); /*����*/
		if(num==-1)
			break;
		getchar();  /*���տո�*/
		scanf("%c",&c); /*�⴬״̬*/
		scanf("%d:%d",&h,&m);
		if(num==0) /*һ���⴬��������*/
		{
			if(count)
				printf("%d %.lf\n",count,sum/count); /*���ʱ�����������*/
			else
				printf("0 0\n");
			sum=0;
			count=0;
			continue;
		}
		if(c=='S')
		{
			a[num].time=h*60+m;
			a[num].flag=1;
		}
		else
		{
			if(a[num].flag) /*�ж��������Ƿ����ȥ��*/
			{
				sum+=h*60+m-a[num].time;  /*����⴬��ʱ��*/
				count++;  /*����*/
				a[num].flag=0; /*��Ǵ��ѹ黹*/
			}
		}
	}
	return 0;
}
