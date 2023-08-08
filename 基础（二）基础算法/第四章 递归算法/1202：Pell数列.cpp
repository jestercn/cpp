#include<bits/stdc++.h>
using namespace std;
//思路：k的范围是10^6，那么本题算法的时间复杂度只能是O(n)
//用数组法，可以支持多次求a_n，减少重复计算 
int a[1000005]; 
int pell(int n)
{
	if(a[n] == 0)
	{
		a[n] = (2*pell(n-1) + pell(n-2))%32767;
	}
	return a[n];
}
int main()
{
	int n, k;
	cin>>n;
	a[1] = 1;
	a[2] = 2;
	for(int i = 0; i < n; ++i)
	{
		cin>>k;
		cout<<pell(k)<<endl;
	}
}
