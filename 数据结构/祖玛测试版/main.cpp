#include <cstdio>
#include <cstring>

const int SZ = 1<<20;
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
}io;

char ch[20001];
char temp[20001];
int size=0,pos;

int res(int a)
{
	int head = a,last = a;
	char elem;

	elem = ch[a];
	while(ch[head] == elem && head) head--;
	if(head || ch[head] != elem) head++;
	while(ch[last] == elem && last < size) last++;
	if(last - head > 2)
	{
		strcpy(temp,ch + last);
		strcpy(ch + head, temp);
		size = size + head - last;
		pos = head;
		return 1;
	}
	else
	return 0;
}

int main()
{
	int i = 0;
	int n;
	char e;

	gets(ch);
	while(ch[size] >= 'A' && ch[size] <= 'Z')size++;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %c",&pos,&e);
		strcpy(temp, ch + pos);//将字符串数组中从第pos个位置开始的所有字符到null结束符为止，复制到temp中
		strcpy(ch + pos + 1, temp);//将temp中刚刚拿到的字符串向后移动一个位置，
		ch[pos] = e;size++;//将字符放入相应位置，并且让size++；
		while(res(pos) && size);
		if(size)
		puts(ch);
		else
		puts("-");
	}
	return 0;
}
