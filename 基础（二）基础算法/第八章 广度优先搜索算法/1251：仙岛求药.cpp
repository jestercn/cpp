#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	int x, y, step;
	Node(){}
	Node(int a, int b, int c):x(a), y(b), step(c) {}
}Node;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char mp[25][25];
bool vis[25][25];
int m, n;

bool isValid(Node nd)
{
	return nd.x >= 1 && nd.x <= m && nd.y >= 1 && nd.y <= n;
}

//返回总步数 
int bfs(int x, int y)
{
	queue<Node> que;
	vis[x][y] = true;
	que.push(Node(x, y, 0));
	while(que.empty() == false)
	{
		Node sel = que.front();
		que.pop();
		for(int i = 0; i < 4; ++i)
		{
			Node nw(sel.x + dir[i][0], sel.y + dir[i][1], sel.step + 1);
			if(isValid(nw) && mp[nw.x][nw.y] != '#' && vis[nw.x][nw.y] == false)
			{
				if(mp[nw.x][nw.y] == '*')
					return nw.step;	
				vis[nw.x][nw.y] = true;
				que.push(nw);
			}
		}
	}
	return -1;	
}

int main()
{
	cin>>m>>n;
	while(!(m == 0 && n == 0))
	{
		int st_x, st_y;
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= n; ++j)
			{
				cin>>mp[i][j];
				if(mp[i][j] == '@')
				{
					st_x = i;
					st_y = j; 
				}
			}
		memset(vis, 0, sizeof(vis));
		cout<<bfs(st_x, st_y)<<endl;
		cin>>m>>n;
	} 
}
