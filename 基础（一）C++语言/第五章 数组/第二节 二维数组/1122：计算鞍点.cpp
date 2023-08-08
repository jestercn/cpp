#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool isFound = false;
    int a[6][6];
    for(int i = 1; i <= 5; ++i)
    	for(int j = 1; j <= 5; ++j)
    		cin>>a[i][j];
	for(int i = 1; i <= 5; ++i)//找到每行的最大值，而后判断该值是否是这一列的最小值 
	{
		int max = a[i][1], m_j = 1;//m_j最大值的j坐标 
		for(int j = 2; j <= 5; ++j)//遍历第i行，j是列号，找到最大值 
		{
			if(a[i][j] > max)
			{
				max = a[i][j];
				m_j = j;
			}
		}
		bool isAndian = true;//a[i][m_j]是否是鞍点 
		for(int k = 1; k <= 5; ++k)//遍历第m_j列 k是行号 
		{
			if(a[k][m_j] < a[i][m_j])//只要在第m_j列找到一个小于a[i][m_j]的元素，那么该点就不是鞍点 
			{
				isAndian = false;
				break;
			}
		}
		if(isAndian)//如果存在鞍点 
		{
			cout<<i<<' '<<m_j<<' '<<a[i][m_j]<<endl;
			isFound = true;
		}	
	}
	if(isFound == false)
		cout<<"not found"<<endl;
    return 0;
}
