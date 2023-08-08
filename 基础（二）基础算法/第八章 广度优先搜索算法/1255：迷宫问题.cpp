#include <bits/stdc++.h>
using namespace std;
#define N 10
typedef struct Pair
{
	int x, y;
	Pair(){}
	Pair(int a, int b):x(a),y(b){}
}Pair;
int mp[N][N];
bool vis[N][N];
Pair lastPos[N][N];//lastPos[i][j]记录路径中i,j的上一个位置 
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
//递归实现倒序输出结果 
void printResRec(Pair p)
{
	if(!(p.x == 0 && p.y == 0))
		printResRec(lastPos[p.x][p.y]);
	cout<<'('<<p.x<<", "<<p.y<<')'<<endl;
}
//用栈实现倒序输出结果 
//void printRes()
//{
//	Pair sel(4, 4); 
//	stack<Pair> stk;
//	stk.push(sel);
//	do
//	{
//		sel = lastPos[sel.x][sel.y];
//		stk.push(sel);
//	}while(!(sel.x == 0 && sel.y == 0));
//	while(stk.empty() == false)
//	{
//		sel = stk.top();
//		stk.pop();
//		cout<<'('<<sel.x<<", "<<sel.y<<')'<<endl;
//	}
//}

bool isValid(int x, int y)
{
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}
void bfs()
{
	queue<Pair> que;
	Pair st(0, 0);
	vis[0][0] = true;
	que.push(st);
	while(que.empty() == false)
	{
		Pair sel = que.front();
		que.pop();
		for(int i = 0; i < 4; ++i)
		{
			Pair nw(sel.x + dir[i][0], sel.y + dir[i][1]);
			if(isValid(nw.x, nw.y) && vis[nw.x][nw.y] == false && mp[nw.x][nw.y] == 0)
			{
				vis[nw.x][nw.y] = true;
				lastPos[nw.x][nw.y] = sel;
				if(nw.x == 4 && nw.y == 4)
					return;
				que.push(nw);
			}
		}
	}
}

int main()
{
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin>>mp[i][j];
	bfs();
	//printRes();
	printResRec(Pair(4, 4));
	return 0;
}
