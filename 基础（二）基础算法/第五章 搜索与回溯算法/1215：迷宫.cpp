#include <bits/stdc++.h>
using namespace std;

char mp[105][105];
int n, ha, la, hb, lb;//ha, la搜索的起始点。hb, lb搜索的目的地。n：矩阵宽 


bool vis[105][105]; 
//搜索的起始点是h, l
bool Search(int h, int l)
{
	bool r_u, r_d, r_l, r_r;//向上下左右搜索的结果
	r_u = r_d = r_l = r_r = false; 
	if(h == hb && l == lb)
		return true;
	else//如果这里是'.'，可以进行下一次搜索 
	{
		vis[h][l] = true;
		if(h > 0 && vis[h - 1][l] == false && mp[h - 1][l] == '.')//如果这个地方没有遍历过且这个地方是'.' 
			r_u = Search(h - 1, l);
		if(r_u) 
			return true;//找到一个能到达的情况，就可以直接返回了，下面的没必要搜索了。 
		if(h < n - 1 && vis[h + 1][l] == false && mp[h + 1][l] == '.')
			r_d = Search(h + 1, l);
		if(r_d) 
			return true;
		if(l > 0 && vis[h][l - 1] == false && mp[h][l - 1] == '.')
			r_l = Search(h, l - 1);
		if(r_l)
			return true;
		if(l < n - 1 && vis[h][l + 1] == false && mp[h][l + 1] == '.')
			r_r = Search(h, l + 1);
		if(r_r)
			return true;
		return false;//上下左右只要有1个方向搜索到目的地，那么返回true。否则返回false。 
	}
}
int main()
{   	
   	int k;
   	cin>>k;
   	for(int i = 0; i < k; ++i)
   	{
   		memset(vis, 0, sizeof(vis));//清空vis数组 
   		cin>>n;
   		for(int l = 0; l < n; ++l)
   			for(int c = 0; c < n; ++c)
   			{
   				cin>>mp[l][c]; 
		   	}
		cin>>ha>>la>>hb>>lb;
		if(mp[ha][la] == '#' || mp[hb][lb] == '#')//提前判断起点或终点为'#'的情况，用Search()也能求出结果，不过更耗时。 
			cout<<"NO"<<endl;
		else
		{
			bool canReach = Search(ha, la);//是否可以到达 
			cout<<(canReach ? "YES" : "NO")<<endl;
		}
	}
    return 0;
}
