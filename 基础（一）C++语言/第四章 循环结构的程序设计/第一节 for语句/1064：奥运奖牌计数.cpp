#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, g, s, b, sum_g = 0, sum_s = 0, sum_b = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>g>>s>>b;
		sum_g += g;
		sum_s += s;
		sum_b += b;
	}
	cout<<sum_g<<' '<<sum_s<<' '<<sum_b<<' '<<sum_g+sum_s+sum_b;
}
