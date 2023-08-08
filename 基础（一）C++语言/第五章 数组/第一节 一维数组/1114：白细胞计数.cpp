#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, min_i, max_i;
	double a[305], ave = 0, dmax = 0;//ave:平均值 dmax:样本减平均值的绝对值的最大值
	cin>>n;
	min_i = max_i = 0;//设a[0]为初始的最大值与最小值 
	for(int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i] > a[max_i])
			max_i = i;
		if(a[i] < a[min_i])
			min_i = i;
	}
	
	for(int i = 0; i < n; ++i)
	{
		if(i != max_i && i != min_i)
			ave += a[i];
	}
	ave /= n-2;
	 
	for(int i = 0; i < n; ++i)
	{
		if(i != max_i && i != min_i)
		{
			if(fabs(a[i] - ave) > dmax)
				dmax = fabs(a[i] - ave);
		}
	}
	cout<<fixed<<setprecision(2)<<ave<<' '<<dmax;
	return 0;
}
