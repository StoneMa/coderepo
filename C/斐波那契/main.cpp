#include <iostream>
#include <string.h>
#define N 1000
using namespace std;
//Fibonacci算数加和； 公式为:f(n) = f(n-1) + f(n-2);
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
//下面 的递归算法效率低，时间复杂度太高，很太多多余的计算，
//更改思路：记录每次计算的结果，将其直接加入到下次递归当中。
int dfs(int n){
    if(n==1||n==2)
        return 1;
    else
        return dfs(n-1)+dfs(n-2);
}


//优化后的斐波那契算法
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
        //或者写return a[n];
        }
}
*/
