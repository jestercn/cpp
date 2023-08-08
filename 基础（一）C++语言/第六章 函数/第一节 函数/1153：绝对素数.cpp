#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

//����λ��n����λ���� 
int transform(int n)
{
	return n % 10 * 10 + n / 10;
}

int main()
{
	for(int i = 10;i <= 99; ++i)
	{
		if(isPrime(i) && isPrime(transform(i)))
			cout<<i<<endl;
	}
}
