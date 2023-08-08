#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[105], n, max = -1000000, s = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i] > max)
			max = a[i];
	}
	for(int i = 0; i < n; ++i)
	{
		if(a[i] != max)
			s += a[i];
	}
	cout<<s;
	return 0;
}
