#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	double s = 0, n = 0;
	cin>>k;
	while(s <= k)
	{
		n++;
		s += 1/n;
	}
	cout<<(int)n;//要求输出整数n 
}
