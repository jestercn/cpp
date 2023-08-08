#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, s = 0, a;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		s += a;
	}
	cout<<fixed<<setprecision(2)<<(double)s/n;
}
