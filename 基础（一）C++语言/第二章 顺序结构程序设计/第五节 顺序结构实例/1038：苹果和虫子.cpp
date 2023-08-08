#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	double n,x,y;
	cin>>n>>x>>y;
	int res = n - ceil(y/x);
	if(res > 0)
		cout<<res;
	else
		cout<<0;
	return 0;
}

