#include <bits/stdc++.h>
using namespace std;
//a[i][j]表示到达第(i,j)点的路径总数
//由于只能向右或向下走，那么要到第0行的点只能从左侧来，要到第0列的点只能从上方来 
//对于不是第0行第0列的点，到这一点，只能是从其上面或左面到达这一点。那么到达这一点的路径数，就是到达其上侧点的路径数加到达其左侧点的路径数
//有a[i][j] = a[i-1][j] + a[i][j-1]
//对于第0行 a[i][j] = a[i][j-1]
//对于第0列 a[i][j] = a[i-1][j]
//如果第(i,j)点是马的控制点，那么a[i][j] = 0
int dir[8][2]={{-1,2},{-1,-2},{1,2},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};

int main() 
{ 
	long long a[25][25];//一定要用long long 
	bool h[25][25];//h[i][j]表示第i，j点是不是马的控制点 
	memset(h, 0, sizeof(h)); 
	int n, m, cx, cy;
	cin>>n>>m>>cx>>cy;
	h[cx][cy] = true;//设置马的控制点 
	for(int i = 0; i < 8; ++i)
	{
		int x = cx + dir[i][0], y = cy + dir[i][1];
		if(x >= 0 && x <= n && y >= 0 && y <= m)
		{
			h[x][y] = true;
			a[x][y] = 0;
		}
	}
	a[0][0] = 1;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
		{
			if(h[i][j] == false)//马控制的点不做计算 
			{
				if(i == 0 && j != 0)
					a[i][j] = a[i][j-1];
				else if(i != 0 && j == 0)
					a[i][j] = a[i-1][j];
				else if(i != 0 && j != 0)
					a[i][j] = a[i-1][j] + a[i][j-1];
			}
		}
	cout<<a[n][m];
	return 0;
}
