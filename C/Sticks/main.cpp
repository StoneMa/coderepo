#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 22
using namespace std;
int vis[M];
int num[M];
int n, m;
bool cmp(int a,int b)//��������ʽ��DESC
{
    return a>b;
}
bool dfs(int remd,int pos,int count,int len)
//remd�����ε�ÿ���ߵ�����ʣ��߳���pos��ǰ����λ�ã�count��������۱ߵĸ�����
{
    int i;
    if(count==4)
    {
        return 1;
    }
    for(i=pos;i<=m-1;i++)
    {
        if((!vis[i])&&remd>=num[i])//mian�������Ѿ��Ա���remd������ĵ�һ��ľ�����Ƚ����˱Ƚϡ�����ʵmain�бȽϵ��ǲ��ִ������ʡȥ����
        {
            vis[i]=1;
            remd=remd - num[i];//����reamdΪʹ����num[i]ľ���󣬻���ĳ��ȡ�
            if(remd==0&&dfs(len,0,count+1,len))//���remdΪ0����ô��ʾ�ñ��Ѿ������۱��Ǻϡ���ô���ѹ��ɵı���+1������dfs��
                                                        //�����dfsĿ���ǽ�����һ��ѭ������Ƿ��Ѿ�������ȫ�����ɣ����Ե�һ������ֱ��д���۱ߡ�
            {
                return 1;
            }else if(dfs(remd,i+1,count,len))//���remd��ȥnum[i]����ʣ�࣬��ô������һ��dfs���ظ�remd�Ĳ�����ֱ��remdΪ0��
            {
                return 1;//�����򵥵ĵط�������ÿ��ľ�����������ϣ�������ʣ�࣬���������ǰ�����в����ϵģ�ֱ�ӷ���return 0��
            }
            //���������һ��ľ��ʱ���ֻ��ǲ������㣬������forѭ�������return 0 ;Ȼ�����εݹ���˵���һ���
            //dfs����Ϊreturn 0��if���������㣬������������Ĵ��룬��ÿ�μ�ȥnum[i]���remd�ӻص�ԭֵ��
            remd = remd + num[i];
            vis[i] = 0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    while(n--)
        {
            memset(vis,0,sizeof(vis));
            int sum = 0;
            scanf("%d",&m);
            for(int i=0;i<=m-1;i++)
            {
                scanf("%d",&num[i]);//num��������¼����ĸ���ľ���ĳ��ȡ�ľ������Ϊm��
                sum+=num[i];
            }
            if(sum%4)
            {
                printf("no\n");
                continue;
            }
            sort(num,num+m,cmp);//sort����cmp��������Ϊ�������С�
            if(sum/4<num[0])//������ľ������������εı߳����������޷���������Ρ�
            {
                printf("no\n");
                continue;//��ӡno��������һ��ѭ����
            }
            if(dfs(sum/4,0,0,sum/4))//�������dfs�����Ǻ��ʵķ�����
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        return 0;
}
