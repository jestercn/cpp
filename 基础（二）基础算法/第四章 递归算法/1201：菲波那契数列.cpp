#include <bits/stdc++.h>
using namespace std;
//如果是第1,2项，返回1，否则，返回前两项的和 
int fib(int i)
{
	if(i <= 2)
		return 1;
	else
		return fib(i-1) + fib(i-2);
}
int main()
{
	int n, a;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		cout<<fib(a)<<endl;
	}
	return 0;
}
