#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, a, f = 0;//a：每个人取药数量 f：未成功取药人数 
	cin>>m>>n;
	int r = m;//剩余的药品数量 
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		if(r < a)//如果剩余的药品少于要取的药的数量 
			f++;
		else
			r -= a;
	} 
	cout<<f;
	return 0;
}
