#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, h, l, c = 0, cm = 0;//h:收缩压，l：舒张压 c:血压连续正常的次数  cm:血压连续正常的最大次数 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>h>>l;
		if(h >= 90 && h <= 140 && l >= 60 && l <= 90)
		{ 
			c++;//如果满足条件，则正常血压次数计数
			if(c > cm)
				cm = c;
		}
		else//如果不满足条件，则正常血压次数置为0 
			c = 0;
	}
	cout<<cm;
	return 0;
}
