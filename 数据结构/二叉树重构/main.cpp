#include <iostream>
#include <cstdio>

using namespace std;
#define  MAX 100
//定义二叉树节点结构结构
typedef struct Node
{
    char data;
    struct Node *lchild,*rchild;

}BiTree;

BiTree *root;


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
