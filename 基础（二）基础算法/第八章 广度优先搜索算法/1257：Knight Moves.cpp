#include <bits/stdc++.h>
using namespace std;
#define N 305
typedef struct Node
{
	int x, y, s;
	Node(){}
	Node(int a, int b, int c):x(a),y(b),s(c){}
}Node;
int l, stx, sty, edx, edy;
bool vis[N][N];
int dir[8][2] = {{-1,2},{-1,-2},{1,2},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};
bool isValid(int x, int y)
{
	return x >= 0 && x < l && y >= 0 && y < l;
}
int bfs()
{
	queue<Node> que;
	vis[stx][sty] = true;
	que.push(Node(stx, sty, 0));
	while(que.empty() == false)
	{
		Node sel = que.front();
		que.pop();
		if(sel.x == edx && sel.y == edy)
			return sel.s;
		for(int i = 0; i < 8; ++i)
		{
			int x = sel.x + dir[i][0], y = sel.y + dir[i][1], s = sel.s + 1;
			if(isValid(x, y) && vis[x][y] == false)
			{
				vis[x][y] = true;
				que.push(Node(x, y, s));
			}
		}
	}
}
int main()
{
	int n; 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>l;	
		cin>>stx>>sty;
		cin>>edx>>edy;
		memset(vis, 0, sizeof(vis));
		cout<<bfs()<<endl;
	}
}
