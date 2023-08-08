#include <bits/stdc++.h>
using namespace std;
char mp[10][10];
bool oc_l[10], oc_c[10];//oc_l[i]表示第i行是否被占用  oc_c[i]表示第i列是否被占用 
bool vis[10][10];
int n, k, ct;//ct：方案计数 

//rem剩余未摆放棋子数 
//遍历顺序为：第mp[0][0]~mp[0][n-1], mp[1][0]~mp[1][n-1],... 
//搜索时，只考虑向遍历顺序中，mp[x][y]后面的棋盘格子放rem个棋子 
void Search(int rem, int x, int y)
{
	if(rem == 0)//所有棋子都摆完，增加方案数 
	{
		ct++;
		return;
	}
	else
	{
		for(int i = x; i < n; ++i)//从第x行开始搜索 
		{
			if(oc_l[i] == false)
			{
				int j;
				if(i == x)//只有第x行，从第y列，即从map[x][y]开始搜索
					j = y;
				else
					j = 0;//对于其它行，从map[][0]开始搜索 
				for(; j < n; ++j)
				{
					if(oc_c[j] == false && mp[i][j] == '#' && vis[i][j] == false)
					{
						oc_l[i] = oc_c[j] = true;//设置这一行列被占用
						vis[i][j] = true; 
						Search(rem - 1, i, j);
						vis[i][j] = false; 
						oc_l[i] = oc_c[j] = false;//解除对这一行列的占用 
					}
				}
			}
		}
	}
}

int main()
{   
   	while(true)
   	{
		cin>>n>>k;
		if(n == -1 && k == -1)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin>>mp[i][j];
		memset(oc_l, 0, sizeof(oc_l));
		memset(oc_c, 0, sizeof(oc_c));
		memset(vis, 0, sizeof(vis));
		ct = 0;
		Search(k, 0, 0);
		cout<<ct<<endl;
	}
    return 0;
}
