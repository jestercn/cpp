#include<bits/stdc++.h>
using namespace std;
//求数字n的因子之和 本题的因子不包括n本身。实际按照数学上的定义，n也是n的因子。 
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
	int n;
	cin>>n;
	for(int i = 2; i <= n; ++i)
	{
		if(sumOfFactor(i) == i)
			cout<<i<<endl;
	}
}
