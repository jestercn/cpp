#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	if(n < 2)
		return false;
	for(int i = 2; i <=sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

//求n的最大质因子 
int maxPrimeFactor(int n)
{
	for(int i = n; i >= 2; --i)
	{
		if(isPrime(i) && n % i == 0)
			return i;
	} 
}
int main()
{
    int m, n;
    cin>>m>>n;
    bool isFirst = true;
    for(int i = m; i <= n; ++i)
    {
    	if(isFirst)
    		isFirst = false;
    	else
    		cout<<',';
    	cout<<maxPrimeFactor(i);
	}
	return 0;
}
