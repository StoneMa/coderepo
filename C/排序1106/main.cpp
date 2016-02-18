#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char str[1010];
char a[1010][1010];
long long  aa[1010];


int main()
{
    int i,j,t;
    int len;
    while(cin>>str)
    {
        len=strlen(str);
        t=0;
        i=0;
        while(str[i]=='5')i++;//去掉前面的5
        for(;i<len;)
        {
            j=0;

            while(str[i]!='5'&&i<len)
            {
                a[t][j++]=str[i];
                i++;
            }
            a[t][j]='\0';
            while(str[i]=='5'&&i<len)i++;
            t++;
        }
        memset(aa,0,sizeof(aa));
        for(i=0;i<t;i++)
        {
            len=strlen(a[i]);
            for(j=0;j<len;j++)
            {
                aa[i]*=10;
                aa[i]+=a[i][j]-'0';

            }
        }

        sort(aa,aa+t);

        for(i=0;i<t-1;i++)
          cout<<aa[i]<<" ";
        cout<<aa[t-1]<<endl;
    }
    return 0;
}
