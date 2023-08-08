#include <bits/stdc++.h>
using namespace std;
//思路：散列存储 
//由于值的范围是-50~50 
//值转为地址：值+50
//地址转为值：地址-50 
int main()
{
	int numArr[105]={}, n, num;//numArr[i+50] = j 表明数字i有j个
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		numArr[num+50]++;
	}
	for(int i = 0; i < 100; ++i)
	{
		if(numArr[i] > n/2)
		{
			cout<<i - 50;
			return 0;
		}
	}
	cout<<"no";
	return 0;
}
