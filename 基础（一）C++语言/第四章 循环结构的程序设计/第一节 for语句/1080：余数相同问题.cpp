#include<bits/stdc++.h>
using namespace std;
//暴力法 
//既然a,b,c都小于等于10^6，且题目保证x有解
//那么可以将x从2循环到10^6，来寻找可行的x 
int main()
{
	int x, a, b, c;
	cin>>a>>b>>c;
	int am, bm, cm;
	for(x = 2; x <= 1000000; ++x)
	{
		am = a % x;
		bm = b % x;
		cm = c % x;
		if(am == bm && bm == cm && cm == am)
		{
			cout<<x;//只求最小值，那么找到一个符合条件的x即可 
			break;
		}
	}
	return 0;
}
