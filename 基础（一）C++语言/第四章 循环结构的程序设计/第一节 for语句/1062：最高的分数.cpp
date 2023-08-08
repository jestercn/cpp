#include<bits/stdc++.h>
using namespace std;
//求最大值 
int main()
{
	int n, max = 0, score;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>score;
		if(score > max)
			max = score;
	}
	cout<<max;
}
