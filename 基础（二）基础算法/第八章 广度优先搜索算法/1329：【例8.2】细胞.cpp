#include <bits/stdc++.h>
using namespace std;
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
typedef struct Pair
{
	int x, y;
	Pair()
	{}
	Pair(int a, int b):x(a),y(b)
	{}
}Pair;

char mp[100][100];
int ct, n, m;;
bool vis[100][100];

Pair getPoint(Pair ori, int dir)
{
    Pair nextP = ori;
    switch(dir)
    {
        case UP:
            nextP.x = ori.x - 1;
            break;
        case LEFT:
            nextP.y = ori.y - 1;
            break;
        case DOWN:
            nextP.x = ori.x + 1;
            break;
        case RIGHT:
            nextP.y = ori.y + 1;
            break;
    }
    return nextP;
}

bool isInField(Pair pos)
{
    if(pos.x >= 0 && pos.x < n && pos.y >= 0 && pos.y < m)
        return true;
    else
        return false;
}

//从坐标x，y开始广搜
void bfs(int x, int y)
{
	Pair que[100000], p;
	int head = 0, tail = 0;
	if(vis[x][y] == false && mp[x][y] != '0')
	{//把相连的一片区域的位置的vis都设为true
		vis[x][y] = true;//入队前访问
		que[++tail] = Pair(x, y);//入队
		while(head != tail)
        {
            p = que[++head];//出队
            for(int dir = 0; dir <= 3; ++dir)
            {
                Pair nextP = getPoint(p, dir);
                if(isInField(nextP) && vis[nextP.x][nextP.y] == false && mp[nextP.x][nextP.y] != '0')
                {
                    vis[nextP.x][nextP.y] = true;
                    que[++tail] = nextP;
                }
            }
        }
        ct++;//细胞数量加1
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 0;i < n; ++i)
		for(int j = 0;j < m; ++j)
        {
			cin>>mp[i][j];
        }
	for(int i = 0;i < n; ++i)
		for(int j = 0;j < m; ++j)
		{
			bfs(i, j);
		}
    cout<<ct;
    return 0;
}
