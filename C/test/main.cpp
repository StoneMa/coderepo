#include <iostream>
#include <stdio.h>
using namespace std;
void f1(int a)
{ cout<<"a="<<a<<endl;
  a=5;
  cout<<"a="<<a<<endl;
	//以下为补充代码
	//cout<<"&a="<<&a<<endl;
}
int main() //main1()
{ int x=47;
  cout<<"x="<<x<<endl;
  f1(x);
  cout<<"x="<<x<<endl;
	//以下为补充代码
	cout<<"&x="<<&x<<endl;
}
