#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int main()
{
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i <= 1000000; ++i)
		a[i] = (2*a[i-1] + a[i-2])%32767;
	int n, x; 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
}
