#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

char transform(char letter)
{
 if(letter>='a'&&letter<='z')
 {
  letter-=32;
 }

 else if(letter>='A'&&letter<='Z')
 {
  letter+=32;
 }

 return letter;
}
int main()
{
 char input[10];
 int count=0;
 for(int i=0;i<10;i++)
 {
  //cin>>input[i];;
  cin.get(input[i]); //使用cin的get函数即可读入回车符
  count++;
  if(input[i]=='\n') break;
 }
 cout<<"原来的字符为：";
 for(int i=0;i<count-1;i++)
 {
  cout<<input[i];
 }
 cout<<endl;
 cout<<"转换后的字符为：";
 for (int i=0;i<count-1;i++)
 {
  cout<<transform(input[i]);
 }
 cout<<endl;
 return 0;
}
