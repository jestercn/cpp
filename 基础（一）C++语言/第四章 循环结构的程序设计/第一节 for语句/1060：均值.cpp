#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double a, s = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		s += a;
	}
	cout<<fixed<<setprecision(4)<<s/n;
}
