#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a, s = 0;
	cin>>n>>m;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		if(a == m)
			s++;
	}
	cout<<s;
	return 0;
}
