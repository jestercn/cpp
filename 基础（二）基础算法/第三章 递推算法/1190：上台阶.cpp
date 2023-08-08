#include <bits/stdc++.h>
using namespace std;
//a[i]表示到第i级台阶的走法
//易得a[1] = 1(1), a[2] = 2(1 1, 2), a[3] = 4(1 1 1, 1 2, 2 1, 3) 括号内是迈台阶的方式 
//对于a[i]，若最后一次要迈1阶，那么之前要先迈i-1阶，迈i-1阶的走法有a[i-1]种，那么这种做法有a[i-1]种 
//同理，若最后一次要迈2阶，先前要迈i-2阶，走法有a[i-2]种。最有一次要迈3阶，走法有a[i-3]种 
//所以有:当i > 3 时，a[i]= a[i-1]+a[i-2]+a[i-3] 
int main()
{
	long long a[80], x;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for(int i = 4; i <= 72; ++i)
		a[i] = a[i-1]+a[i-2]+a[i-3];
	cin>>x;
	while(x != 0)
	{
		cout<<a[x]<<endl;
		cin>>x;
	}
	
	return 0;
}
