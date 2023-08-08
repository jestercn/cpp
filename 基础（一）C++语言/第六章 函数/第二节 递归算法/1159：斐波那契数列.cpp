#include<bits/stdc++.h>
using namespace std;
//本题说法于一般斐波那契数列不同 
int fib(int n)
{
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}
