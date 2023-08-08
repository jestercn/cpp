#include <bits/stdc++.h>
using namespace std;
//先求出每天上课总时间。一周7天，7个上课时间为7个数，求这7个数的最大值 
int main()
{
	int a[10], inSch, outSch;
	for(int i = 1; i <= 7; ++i)
	{
		cin>>inSch>>outSch;
		a[i] = inSch + outSch;
	}
	int maxDay = 1;
	for(int i = 1; i <= 7; ++i)
	{
		if(a[i] > a[maxDay])
			maxDay = i;
	}
	if(a[maxDay] <= 8)//最大的上课时间不及8小时，不至于不高兴 
		cout<<0;
	else
		cout<<maxDay;
	return 0;
}
