#include <bits/stdc++.h>
using namespace std;
#define N 105
typedef struct Node
{
	int x, y, s;
	Node(){}
	Node(int a, int b, int c):x(a),y(b),s(c){}
}Node;
int n, m, dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char mp[N][N];
bool vis[N][N];
bool isValid(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs(int stx,int sty)
{
	queue<Node> que;
	Node st(stx, sty, 0);
	vis[stx][sty] = true;
	que.push(st);
	while(que.empty() == false)
	{
		Node sel = que.front();
		que.pop();
		if(mp[sel.x][sel.y] == 'T')
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
	
}
int main()
{
	int stx, sty;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			cin>>mp[i][j];
			if(mp[i][j] == 'S')
			{
				stx = i;
				sty = j;
			}
		}
	cout<<bfs(stx, sty);
	return 0;
}
