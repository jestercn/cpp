#include <bits/stdc++.h>
using namespace std;
//桶排序 
int main()
{
	int n, num, count = 0, a[105], a_i = 0;
	cin>>n;
	//用散列存储去重
	bool hasNum[1005]={};
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		hasNum[num] = true;
	}
	for(int i = 1; i <= 1005; ++i)
	{
		if(hasNum[i])
		{
			a[a_i++] = i;
			count++; 
		}
	}
	cout<<count<<endl;
	for(int i = 0; i < a_i; ++i)
		cout<<a[i]<<' ';
}
