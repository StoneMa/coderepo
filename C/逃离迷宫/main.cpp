#include <iostream>
#include <stdio.h>
using namespace std;
#define inf 0x3fffffff
#define M 105
	//1��wan����ת������֦��2��step���ڲ�����֦���Ͳ���vis��Ƿ�����
int r, c, ex, ey, k, wan[M][M];
char map[M][M];
int x_move[4] = {-1, 0, 1, 0};
int y_move[4] = {0, 1, 0, -1};
bool flag;

void dfs (int x, int y, int dir)	//dirΪ��ǰ����
{
    if (x == ex && y == ey)
    {
        if (wan[x][y] <= k)
            flag = true;
        return ;
    }
	if (wan[x][y] > k)	//ת��������k������������
        return ;
    //x !=ex && y != ey ˵������������תһ���䣬�����Ѿ�������ת��
    if (wan[x][y] == k && x !=ex && y != ey)
        return ;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + x_move[i];
        int ty = y + y_move[i];
        if (tx < 0 || tx >= r || ty < 0 || ty >= c)
            continue;
//ת������Ȳ��ɼ�����������wan[tx][ty] < wan[x][y]������wan[tx][ty] <= wan[x][y]
        if (map[tx][ty] == '*' || wan[tx][ty] < wan[x][y])	//ת������֦
            continue;
        if (dir != -1 && i != dir && wan[tx][ty] < wan[x][y] + 1)	//ת������֦
            continue;
        wan[tx][ty] = wan[x][y];
        if (dir != -1 && i != dir)
            wan[tx][ty]++;	//����������ת��+1
        dfs (tx, ty, i);
        if (flag)
            return ;
    }
}

int main()
{
    int t, i, j, sx, sy;	//sx�� sy�����
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d%d", &r, &c);
        for (i = 0; i < r; i++)
            scanf ("%s", map[i]);
        scanf ("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);
        sx--, sy--, ex--, ey--;		//�Ҵ�0��ʼ��ţ�����Ŀ�Ǵ�1��ʼ
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                wan[i][j] = inf;	//��ʼ��ת�����Ͳ���Ϊ�����
        wan[sx][sy] = 0;	//��������ת����
        flag = false;
        dfs (sx, sy, -1);	//һ��ʼ���������ⷽ�������跽��Ϊ-1
        if (flag)
            puts ("yes");
        else puts ("no");
    }
    return 0;
}
