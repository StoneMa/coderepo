#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
int x;
int y;
int step;
Node(int x1,int y1,int step1):x(x1),y(y1),step(step1){}
};
int BFS()
{
Node node(0,0,0);
queue<Node>q;
while(!q.empty())q.pop();
q.push(node);
while(!q.empty())
{
node=q.front();
q.pop();
if(node.x==n-1&&node.y==n-1)
{
return node.step;
}
visit[node.x][node.y]=1;
for(inti=0;i<4;i++)
{
int x=node.x+stepArr[i][0];
int y=node.y+stepArr[i][1];
if(x>=0&&y>=0&&x<n&&y<n&&visit[x][y]==0&&mazeArr[x][y]==0)
{
visit[x][y]=1;
Node next(x,y,node.step+1);
q.push(next);
}
}
}
return-1;
}
