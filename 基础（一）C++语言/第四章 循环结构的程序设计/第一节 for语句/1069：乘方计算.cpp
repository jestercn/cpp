#include<bits/stdc++.h>
using namespace std;
//此题只考察基本的循环。也可以用“快速幂”的算法来做 
int main()
{
	int a, n, s = 1;
	cin>>a>>n;
	for(int i = 0; i < n; ++i)
	{
		s *= a;
	}
	cout<<s;
	return 0;
}
