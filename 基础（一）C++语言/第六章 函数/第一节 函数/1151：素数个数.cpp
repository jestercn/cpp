#include<bits/stdc++.h>
using namespace std;
//判断是否是质数 
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, s = 0;
	cin>>n;
	for(int i = 2; i <= n; ++i)
	{
		if(isPrime(i))
			s++;
	}
	cout<<s;
}
