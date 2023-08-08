#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a)
{
	if(a < 2)
		return false;
	for(int i = 2; i <= sqrt(a); ++i)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int buk[30] = {}, maxn = 0, minn = 150, res = 0;
	char s[105];
	cin>>s;
	for(int i = 0; i < strlen(s); ++i)
	{
		buk[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; ++i)
	{
		if(buk[i] > 0)
		{
			if(buk[i] > maxn)
				maxn = buk[i];
			if(buk[i] < minn)
				minn = buk[i];
		}
	}
	res = maxn - minn;
	if(isPrime(res))
	{
		cout<<"Lucky Word"<<endl;
		cout<<res;
	}
	else
	{
		cout<<"No Answer"<<endl;
		cout<<0;
	}
	return 0;
}
