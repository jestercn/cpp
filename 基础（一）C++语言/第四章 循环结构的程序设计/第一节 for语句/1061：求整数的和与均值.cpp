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
	cout<<(int)s<<' '<<fixed<<setprecision(5)<<s/n;
}
