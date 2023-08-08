#include<bits/stdc++.h>
using namespace std;
//求数字n的因子之和 因子不包括n本身。 
int sumOfFactor(int n)
{
	int s = 0;
	for(int i = 1; i < n; ++i)
	{
		if(n % i == 0)//如果i是n的因子 
			s += i;
	}
	return s;
}

int main()
{
	int a, b;
	for(int i= 2; true; ++i)
	{
		a = i;
		b = sumOfFactor(a);
		if(a != b && a == sumOfFactor(b))
		{
			if(a < b)
				cout<<a<<' '<<b;
			else
				cout<<b<<' '<<a;
			break;
		}
	}
	return 0;
}
