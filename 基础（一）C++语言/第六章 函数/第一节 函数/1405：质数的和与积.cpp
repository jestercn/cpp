#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a)
{
	for(int i = 2; i <= sqrt(a); ++i)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int s, mx = 0;
	cin>>s;
	for(int i = 1; i <= s/2 ; ++i)
	{
		if(isPrime(i) && isPrime(s - i))
		{
			if(i * (s-i) > mx)
				mx = i * (s-i);
		}
	}
	cout<<mx;
	return 0;
}
