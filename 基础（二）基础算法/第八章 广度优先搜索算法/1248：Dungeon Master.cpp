#include<bits/stdc++.h>
using namespace std;
typedef struct Vec
{
	int l, r, c;//层，行，列
	Vec(int _l, int _r, int _c):l(_l), r(_r), c(_c){}
	Vec(){}
}Vec;
typedef struct Node
{
	Vec v;
	int time;
	Node(){}
	Node(Vec _v, int _t):v(_v), time(_t){}
}Node;
char mp[105][105][105];//层 行 列 
bool vis[105][105][105];
Vec v_t[6];//取一个位置可以到达其他位置的偏移量 
int lay, row, col;
//v是否在定义的区域内 
bool isValid(Vec v)
{
	if(v.l >= 1 && v.l <= lay && v.r >= 1 && v.r <= row && v.c >= 1 && v.c <= col)
		return true;
	else
		return false;
}

//初始化偏移量 
void initVtilt()
{
	v_t[0] = Vec(-1, 0, 0);
	v_t[1] = Vec(1, 0, 0);
	v_t[2] = Vec(0, 1, 0);
	v_t[3] = Vec(0, -1, 0);
	v_t[4] = Vec(0, 0, 1);
	v_t[5] = Vec(0, 0, -1);
}

int main()
{
	initVtilt();
	int time;
	bool isReached;
	Vec v_st;
	cin>>lay>>row>>col;
	queue<Node> que;
	while(!(lay == 0 && row == 0 && col == 0))
	{
		isReached = false;
		que = queue<Node>();
		memset(vis, 0, sizeof(vis));
		for(int l = 1; l <= lay; ++l)
			for(int r = 1; r <= row; ++r)
				for(int c = 1; c <= col; ++c)
				{
					cin>>mp[l][r][c];
					if(mp[l][r][c] == 'S')
						v_st = Vec(l, r, c);
				}
		que.push(Node(v_st, 0));
		vis[v_st.l][v_st.r][v_st.c] = true;
		while(que.empty() == false)
		{
			Node n_sel = que.front();
			que.pop();
			Vec v_sel = n_sel.v;
			for(int i = 0; i < 6; ++i)
			{
				Vec v_new = Vec(v_sel.l + v_t[i].l, v_sel.r + v_t[i].r, v_sel.c + v_t[i].c);
				if(isValid(v_new) && mp[v_new.l][v_new.r][v_new.c] != '#' && vis[v_new.l][v_new.r][v_new.c] == false)
				{
					time++;
					vis[v_new.l][v_new.r][v_new.c] = true;
					que.push(Node(v_new, n_sel.time + 1));
					if(mp[v_new.l][v_new.r][v_new.c] == 'E')
					{
						isReached = true;
						time = n_sel.time + 1;
						break;
					}
				}
			}
			if(isReached)
				break;
		}
		if(isReached)
			cout<<"Escaped in "<<time<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
		cin>>lay>>row>>col;
	}
}
