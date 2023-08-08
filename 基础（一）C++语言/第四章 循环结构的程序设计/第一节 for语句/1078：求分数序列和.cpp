#include<bits/stdc++.h>
using namespace std;

int main()
{
	double s = 0, q = 2, p = 1, temp;
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		s += q / p;
		temp = q;
		q = q + p;
		p = temp;
	} 
	cout<<fixed<<setprecision(4)<<s;
}
