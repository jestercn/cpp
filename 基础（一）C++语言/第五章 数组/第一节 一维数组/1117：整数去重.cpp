#include <bits/stdc++.h>
using namespace std;
//散列存储 
int main()
{
	bool isExist[5005] = {};
	int n, a[20005];
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//输出数字后,把isExist[a[i]]设为true，若遇到isExist[a[i]]为true，则不输出 
	for(int i = 0; i < n; ++i)
	{
		if(isExist[a[i]] == false)
		{
			cout<<a[i]<<' ';
			isExist[a[i]] = true;	
		}
	}
	return 0;
}
