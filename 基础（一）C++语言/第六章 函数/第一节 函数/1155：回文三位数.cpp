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

//判断n是否是回文数字 
bool isHuiwen(int n)
{
	int newNum = 0;//构造n反向的数字，若n反向的数字与n相等，那么n就是一个回文数 
	for(int a = n; a > 0; a /= 10)
	{
		newNum = newNum * 10 + a % 10;
	}
	return n == newNum;
}

int main()
{
	for(int i = 100;i <= 999; ++i)
	{
		if(isPrime(i) && isHuiwen(i))
			cout<<i<<endl;
	}
	return 0;
}
