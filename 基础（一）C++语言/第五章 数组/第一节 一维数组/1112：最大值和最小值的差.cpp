#include <bits/stdc++.h>
using namespace std;

int main()
{
	int max, min, n, a;
	cin>>n;
	cin>>a;
	max = min = a;//先把最大最小值设为第一个值 
	for(int i = 1; i < n; ++i)//循环n-1次，读入下面的数字 
	{
		cin>>a;
		if(a > max)
			max = a;
		if(a < min)
			min = a;
	}
	cout<<max-min;
	return 0;
}
