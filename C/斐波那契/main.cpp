#include <iostream>
#include <string.h>
#define N 1000
using namespace std;
//Fibonacci�����Ӻͣ� ��ʽΪ:f(n) = f(n-1) + f(n-2);
int dfs(int n);
void init(int a[]);

int a[N];
int n;
int main(){
    cin>>n;
    init(a);
    cout <<dfs(n) << endl;
    return 0;
}
void init(int a[]){
    memset(a,0,sizeof(a));
}
//���� �ĵݹ��㷨Ч�ʵͣ�ʱ�临�Ӷ�̫�ߣ���̫�����ļ��㣬
//����˼·����¼ÿ�μ���Ľ��������ֱ�Ӽ��뵽�´εݹ鵱�С�
int dfs(int n){
    if(n==1||n==2)
        return 1;
    else
        return dfs(n-1)+dfs(n-2);
}


//�Ż����쳲������㷨
/*
int dfs(int n){
    if(a[n]!=0){
        return a[n];
    }
    if(n==1||n==2){
            a[1] = a[2] = 1;
        return 1;
    }
    else{
        a[n] = dfs(n-1)+dfs(n-2);
        return dfs(n-1)+dfs(n-2);
        //����дreturn a[n];
        }
}
*/
