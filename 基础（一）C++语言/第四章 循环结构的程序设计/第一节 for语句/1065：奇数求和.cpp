#include<bits/stdc++.h>
using namespace std;
//考察：循环 取模 加和  
int main()
{
	int m, n, s = 0;
	cin>>m>>n;
	for(int i = m; i <= n; ++i)
	{
		if(i%2 == 1)
			s += i;
	}
	cout<<s;
}
