#include <bits/stdc++.h>
using namespace std;
//深搜求解01背包问题
int m, n, sumVal, maxVal, sumWei;//sumWei:已选择物品的总重量 sumVal:已经选择的物品的价值总和 maxVal：可能达到的最大价值 
int wei[35], val[35], ct;//wei[i]:第i个物品的重量  val[i]:第i个物品的价值 

//要不要选取第i个物品 
void Search(int i)
{
	ct++;
	if(i > n)
	{
		if(sumVal > maxVal)
			maxVal = sumVal;
	}
	else
	{
		Search(i + 1);//不加第i个物品
		if(sumWei + wei[i] <= m) //如果加第i个物品后还没有超重 
		{	
			sumWei += wei[i];
			sumVal += val[i];
			Search(i + 1);//加第i个物品
			sumWei -= wei[i];
			sumVal -= val[i]; 
		}
	}
}
int main()
{
	cin>>m>>n;
	int w, v, j;
//	for(int i = 1; i <= n; ++i)
//		cin>>wei[i]>>val[i];
	for(int i = 1; i <= n; ++i)
	{
		cin>>w>>v;//插入排序 
		for(j = i; j > 1; --j)
		{
			if(wei[j - 1] < w)
				wei[j] = wei[j - 1];
			else
				break;
		}
		wei[j] = w;
		val[j] = v;
	}
	Search(1);
	cout<<maxVal<<endl; 
	cout<<"Search Times:"<<ct;
    return 0;
}
/*
300 10
95 89
75 59
23 19
73 43
50 100
22 72
6 44
57 16
89 7
98 64

out:
388

一般顺序：1377次
从大到小顺序：1138次 
从小到大顺序：1391次 
*/ 
