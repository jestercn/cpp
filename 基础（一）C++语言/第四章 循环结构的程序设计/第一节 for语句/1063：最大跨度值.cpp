#include<bits/stdc++.h>
using namespace std;
//求最大最小值 
int main()
{
	int n, max = 0, min = 10000, a;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		if(a > max)
			max = a;
		if(a < min)
			min = a;
	}
	cout<<max-min;
}
