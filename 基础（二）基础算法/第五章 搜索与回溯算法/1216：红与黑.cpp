#include <bits/stdc++.h>
using namespace std;
char mp[25][25];
int l, c, ct;//ct:黑色瓷砖计数 l是行数, c是列数
bool vis[25][25]; 
void Search(int x, int y)
{
	if(mp[x][y] == '#')
		return;
	else if(vis[x][y])
		return;
	else
	{	
		ct++;
		vis[x][y] = true;
		if(x > 0)
			Search(x - 1, y);
		if(x < l - 1)
			Search(x + 1, y);
		if(y > 0)
			Search(x, y - 1);
		if(y < c - 1)
			Search(x, y + 1);
	}
}

int main()
{   
	int sx, sy;//sx,sy起始位置 
   	while(true)
   	{
   		cin>>c>>l;//题中w是列数，即为c，y是行数，即为l 
   		if(c == 0 && l == 0)//当在一行中读入的是两个零时，表示输入结束。
   			break;
   		for(int i = 0; i < l; ++i) 
   			for(int j = 0; j < c; ++j)
   			{
				cin>>mp[i][j];
				if(mp[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		memset(vis, 0, sizeof(vis));
   		ct = 0;
		Search(sx, sy);
		cout<<ct<<endl;
	}
    return 0;
}
