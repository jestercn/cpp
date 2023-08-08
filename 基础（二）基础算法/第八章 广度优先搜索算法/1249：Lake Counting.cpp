#include<bits/stdc++.h>
using namespace std;
typedef struct Pair
{
	int x, y;
	Pair(){}
	Pair(int a, int b):x(a),y(b){}
}Pair;
int n, m;
char mp[120][120];
bool vis[120][120];
int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
Pair que[100000];
int head, tail, ct;
bool isValid(Pair p)
{
	if(p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m)
		return true;
	else
		return false;
}

void bfs(Pair p_st)
{
	if(vis[p_st.x][p_st.y] || mp[p_st.x][p_st.y] == '.')
		return;
	ct++;
	Pair p_new, p_sel;
	head = tail = 0;
	vis[p_st.x][p_st.y] = true;
	que[++tail] = p_st;
	while(head != tail)
	{
		p_sel = que[++head];
		for(int i = 0; i < 8; ++i)
		{
			p_new.x = p_sel.x + dir[i][0];
			p_new.y = p_sel.y + dir[i][1];
			if(isValid(p_new) && vis[p_new.x][p_new.y] == false && mp[p_new.x][p_new.y] == 'W')
			{
				vis[p_new.x][p_new.y] = true;
				que[++tail] = p_new;
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			cin>>mp[i][j];
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			bfs(Pair(i, j));
		}
	cout<<ct;
	return 0;
}
