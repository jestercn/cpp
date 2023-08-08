#include <bits/stdc++.h>
using namespace std;
//s[i][j]表示从1，1位置到第i，j位置的路线总数。
//由于蚂蚁只能向右或上走，那么第i，j位置只能是从左面或从下面来的
//到第i，j的路线数，就是到它左面格子的路线数加上到它下面格子的路线数
//有当j>1 && i>1时 s[i][j] = s[i][j-1] + s[i-1][j];
//当j == 1时 第一列的格子的路线数等于其上面格子的路线数，有：s[i][j] = s[i-1][j];
//当i == 1时 第一行格子的路线数等于其左面格子的路线数，有：s[i][j] = s[i][j-1];
int main()
{
    int m, n, s[25][25];
    cin>>m>>n;
    s[1][1] = 1;//初始位置到初始位置只有一种路线 
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(i == 1 && j == 1)//1,1位置不考虑 
				continue; 
			if(i == 1)//第一行 
				s[i][j] = s[i][j-1];
			else if(j == 1)//第一列
				s[i][j] = s[i-1][j]; 
			else//不在第一行第一列 
				s[i][j] = s[i][j-1] + s[i-1][j];
		}
	cout<<s[m][n];
    return 0;
}
