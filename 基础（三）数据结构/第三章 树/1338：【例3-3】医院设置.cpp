#include <bits/stdc++.h>
using namespace std;
//该题本质上是图的遍历问题
//使用带有指向双亲结点指针的树来求解 
typedef struct
{
	int val;//人数
	int left, right, parent;
}Node;
Node node[200]; 

bool vis[200];//表示各结点是否已访问过
int dist[200];//表示各结点距离某结点的距离
 
//在第fromp结点处建医院，求各地人到医院的距离，存在dist数组中 
//做法为从fromp出发进行深度优先搜索
//distance：fromp结点参数距离出发点有多远的距离 
int getDistance(int fromp, int distance)
{
	vis[fromp] = true;
	dist[fromp] = distance;
	int selp = node[fromp].parent;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
	selp = node[fromp].left;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
	selp = node[fromp].right;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
}

//求距离和 
int sumDis(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; ++i)
	{
		sum += node[i].val * dist[i];
	}
	return sum;
}

int main()
{
	int n, val, left, right, min = INT_MAX, sum;
	cin>>n; 
	for(int i = 1; i <= n; ++i)//第i号结点存储在node[i]
	{
		cin>>val>>left>>right;
		node[i].val = val;//设置i结点 
		node[i].left = left;
		node[i].right = right;
		if(left != 0)//将i结点左右孩子的双亲设为i 
			node[left].parent = i;
		if(right != 0)
			node[right].parent = i;
	}
	for(int i = 1; i <= n; ++i)
	{
		memset(vis, false, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		getDistance(i, 0);
		sum = sumDis(n);
		if(sum < min)
			min = sum; 
	}
	cout<<min;
	return 0;
}
