#include<bits/stdc++.h>
using namespace std;
int digit(int n, int k)
{
	if(k == 1)
		return n % 10;
	else
		return digit(n / 10, k - 1);
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<<digit(n, k);
	return 0;
}
