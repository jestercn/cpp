#include<bits/stdc++.h>
using namespace std;

int main()
{
	double s = 0, sign = 1;
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		s += sign * 1 / i;
		sign = -sign;
	}
	cout<<fixed<<setprecision(4)<<s;
	return 0;
}
