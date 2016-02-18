#include<stdio.h>
#include<string.h>
struct boat
{
	int time;
	int flag;
}a[105];
int count; /*记录次数*/
double sum; /*记录时间*/
int main()
{
	int num,h,m;
	char c;
	sum=0;
	count=0;
	memset(a,0,sizeof(a)); /*初始化*/
	while(1)
	{
		scanf("%d",&num); /*船号*/
		if(num==-1)
			break;
		getchar();  /*吸收空格*/
		scanf("%c",&c); /*租船状态*/
		scanf("%d:%d",&h,&m);
		if(num==0) /*一天租船工作结束*/
		{
			if(count)
				printf("%d %.lf\n",count,sum/count); /*输出时结果四舍五入*/
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
			if(a[num].flag) /*判断这条船是否租出去了*/
			{
				sum+=h*60+m-a[num].time;  /*求出租船总时间*/
				count++;  /*次数*/
				a[num].flag=0; /*标记船已归还*/
			}
		}
	}
	return 0;
}
