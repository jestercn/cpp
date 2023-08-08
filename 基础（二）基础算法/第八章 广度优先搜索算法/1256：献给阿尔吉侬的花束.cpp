#include<bits/stdc++.h>
using namespace std;
#define N 205
typedef struct Node
{
	int x, y, s;
	Node(){}
	Node(int a, int b, int c):x(a), y(b), s(c){}
}Node;
int r, c, dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char mp[N][N];
bool vis[N][N];
bool isValid(int x, int y)
{
	return x >= 1 && x <= r && y >= 1 && y <= c;
}
int bfs(int stx, int sty)
{
	queue<Node> que;
	Node st(stx, sty, 0);
	vis[stx][sty] = true;
	que.push(st);
	while(que.empty() == false)
	{
		Node sel = que.front();
		que.pop();
		if(mp[sel.x][sel.y] == 'E')
			return sel.s;
		for(int i = 0; i < 4; ++i)
		{
			int x = sel.x + dir[i][0], y = sel.y + dir[i][1], s = sel.s + 1; 
			if(isValid(x, y) && vis[x][y] == false && mp[x][y] != '#')
			{
				vis[x][y] = true;
				que.push(Node(x, y, s));
			}
		}
	}
	return -1;//如果没有找到终点 
}
int main()
{
	int t, res, stx, sty;
	cin>>t;
	for(int k = 0; k < t; ++k)
	{
		cin>>r>>c;
		for(int i = 1; i <= r; ++i)
			for(int j = 1; j <= c; ++j)
			{
				cin>>mp[i][j];
				if(mp[i][j] == 'S')
				{
					stx = i;
					sty = j;
				}
			}
		memset(vis, 0, sizeof(vis));
		res = bfs(stx, sty);
		if(res > 0)
			cout<<res<<endl;
		else
			cout<<"oop!"<<endl;
	}
    return 0;
}
